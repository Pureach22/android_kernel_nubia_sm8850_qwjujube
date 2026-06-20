__int64 __fastcall md_add_elf_header(_QWORD *a1)
{
  __int64 v1; // x8
  __int64 v3; // x12
  __int64 v4; // x9
  unsigned int v5; // w11
  __int64 v6; // x10
  __int64 v7; // x21
  __int64 v8; // x22
  __int64 result; // x0
  __int64 v10; // x9
  __int64 v11; // x9
  __int64 v12; // x9

  v1 = minidump_elfheader;
  v3 = *(_QWORD *)(minidump_elfheader + 32);
  v4 = *(unsigned __int16 *)(minidump_elfheader + 60);
  v5 = *(unsigned __int16 *)(minidump_elfheader + 56);
  v6 = *(_QWORD *)(minidump_elfheader + 40) + minidump_elfheader;
  *(_WORD *)(minidump_elfheader + 60) = v4 + 1;
  v7 = v6 + (v4 << 6);
  v8 = v3 + v1 + 56LL * v5;
  *(_WORD *)(v1 + 56) = v5 + 1;
  *(_DWORD *)(v7 + 4) = 1;
  result = set_section_name((__int64)a1);
  *(_DWORD *)v7 = result;
  *(_QWORD *)(v7 + 16) = a1[3];
  v10 = a1[5];
  *(_QWORD *)(v7 + 8) = 1;
  *(_QWORD *)(v7 + 32) = v10;
  v11 = qword_10038;
  *(_QWORD *)(v7 + 56) = 0;
  *(_QWORD *)(v7 + 24) = v11;
  *(_DWORD *)v8 = 1;
  *(_QWORD *)(v8 + 8) = qword_10038;
  *(_QWORD *)(v8 + 16) = a1[3];
  *(_QWORD *)(v8 + 24) = a1[4];
  v12 = a1[5];
  *(_DWORD *)(v8 + 4) = 6;
  *(_QWORD *)(v8 + 32) = v12;
  *(_QWORD *)(v8 + 40) = v12;
  qword_10038 += *(_QWORD *)(v7 + 32);
  return result;
}
