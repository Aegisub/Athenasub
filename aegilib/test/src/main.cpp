// Copyright (c) 2008, Rodrigo Braz Monteiro
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
//
//   * Redistributions of source code must retain the above copyright notice,
//     this list of conditions and the following disclaimer.
//   * Redistributions in binary form must reproduce the above copyright notice,
//     this list of conditions and the following disclaimer in the documentation
//     and/or other materials provided with the distribution.
//   * Neither the name of the Aegisub Group nor the names of its contributors
//     may be used to endorse or promote products derived from this software
//     without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
// ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
// LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
// CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
// SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
// INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
// CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
// ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
// POSSIBILITY OF SUCH DAMAGE.
//
// -----------------------------------------------------------------------------
//
// AEGISUB/AEGILIB
//
// Website: http://www.aegisub.net
// Contact: mailto:amz@aegisub.net
//

#include <aegilib/aegilib.h>
#include <wx/wfstream.h>
#include <iostream>
#include "text_file_reader.h"
#include "text_file_writer.h"

int main () {
	using namespace std;
	using namespace Aegilib;

	cout << "Aegilib test program by amz.\n\n";

	try {
		// Set up the lib
		FormatManager::InitializeFormats();

		// Subtitles model
		Model subs;

		// Load subtitles
		cout << "Loading file... ";
		String filename = L"subs_in.ass";
		const Format *handler = FormatManager::GetFormatFromFilename(filename);
		subs.LoadFile(wxFileInputStream(filename),handler);
		cout << "Done.\n";

		// Modify subtitles
		cout << "Modifying file...";
		cout << "Done.\n";

		// Save subtitles
		cout << "Saving file... ";
		filename = L"subs_out.ass";
		handler = FormatManager::GetFormatFromFilename(filename);
		subs.SaveFile(wxFileOutputStream(filename),handler);
		cout << "Done.\n";
	}

	catch (Exception &e) {
		cout << "\n\nException: " << e.GetMessage().mb_str(wxConvUTF8) << endl << endl;
	}
}
