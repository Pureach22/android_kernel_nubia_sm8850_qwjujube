__int64 __fastcall md_smem_add_header(__int64 a1, __int64 a2, unsigned int a3)
{
  __int64 v3; // x21
  __int64 v6; // x9
  unsigned __int64 v7; // x10
  __int64 v8; // x9
  unsigned __int64 v9; // x13
  __int64 v10; // x10
  __int64 result; // x0

  v3 = qword_1100F8;
  *(_BYTE *)(qword_1100F8 + 8) = 0;
  *(_QWORD *)v3 = *(_QWORD *)"KELF_HDR";
  v6 = minidump_elfheader << 8 >> 8;
  v7 = v6 + 0x8000000000LL;
  v8 = v6 - kimage_voffset;
  v9 = v7 >> 38;
  v10 = v7 + memstart_addr;
  if ( !v9 )
    v8 = v10;
  *(_QWORD *)(v3 + 24) = v8;
  *(_QWORD *)(v3 + 32) = a3;
  *(_DWORD *)(a1 + 4) = 1;
  *(_QWORD *)(a1 + 56) = 0;
  *(_QWORD *)(a1 + 8) = 0;
  *(_QWORD *)(a1 + 16) = &minidump_table;
  result = set_section_name((__int64)"minidump_table");
  *(_DWORD *)a1 = result;
  *(_WORD *)(a2 + 60) = 4;
  *(_DWORD *)(v3 + 20) = 1447119945;
  return result;
}
