__int64 qcom_va_md_elf_panic_handler()
{
  __int64 v0; // x8
  __int64 v1; // x9
  __int64 v2; // x23
  __int64 v3; // x19
  __int64 v4; // x11
  __int64 v5; // x12
  __int64 v6; // x22
  unsigned __int64 v7; // x24
  __int64 v8; // x8
  __int64 v10; // x22
  unsigned __int16 v11; // w8
  unsigned __int64 v12; // x21
  unsigned int *v13; // x23
  __int64 v14; // x9
  __int64 v15; // x1
  void (__fastcall *v16)(__int64, __int64); // x8
  __int64 v17; // x0
  unsigned __int64 v18; // x9
  __int16 v19; // w11
  unsigned __int64 v20; // x28
  __int64 v21; // x8
  __int64 v22; // x8
  __int64 v23; // x9
  const void *v24; // x1

  if ( dword_7790 )
  {
    if ( byte_77F9 == 1 )
    {
      v0 = qword_77A0;
      v1 = qword_77A8 << 6;
      *(_QWORD *)qword_77A0 = 0x10102464C457FLL;
      *(_QWORD *)(v0 + 16) = 0x100B70004LL;
      *(_QWORD *)(v0 + 32) = v1 + 64;
      *(_QWORD *)(v0 + 40) = 64;
      v2 = qword_7788;
      *(_DWORD *)(v0 + 52) = 3670080;
      v3 = qword_77A0;
      *(_WORD *)(v0 + 58) = 64;
      *(_WORD *)(v0 + 62) = 1;
      LOWORD(v1) = *(_WORD *)(v3 + 60);
      v5 = *(_QWORD *)(v3 + 32);
      v4 = *(_QWORD *)(v3 + 40);
      qword_7798 = 1;
      v6 = v5 + 56 * qword_77B0;
      *(_WORD *)(v3 + 60) = v1 + 2;
      v7 = v4 + v3 + ((unsigned __int64)(unsigned __int16)(v1 + 1) << 6);
      *(_DWORD *)(v7 + 4) = 3;
      *(_QWORD *)(v7 + 24) = v6;
      *(_DWORD *)v7 = set_sec_name(v3, "STR_TBL");
      v8 = qword_77C0;
      *(_QWORD *)(v7 + 32) = qword_77C0;
      if ( qword_77A8 != 2 )
      {
        v10 = v8 + v6;
        v11 = *(_WORD *)(v3 + 60);
        v12 = 0;
        v13 = (unsigned int *)(v2 + 40);
        do
        {
          v20 = *(_QWORD *)(v3 + 40) + v3 + ((unsigned __int64)v11 << 6);
          *(_DWORD *)(v20 + 4) = 1;
          *(_DWORD *)v20 = set_sec_name(v3, v13 - 8);
          v21 = *v13;
          *(_QWORD *)(v20 + 8) = 1;
          *(_QWORD *)(v20 + 24) = v10;
          *(_QWORD *)(v20 + 32) = v21;
          v22 = *(_QWORD *)(v3 + 32) + v3 + 56LL * *(unsigned __int16 *)(v3 + 56);
          *(_DWORD *)v22 = 1;
          *(_QWORD *)(v22 + 8) = v10;
          v23 = *v13;
          *(_DWORD *)(v22 + 4) = 6;
          *(_QWORD *)(v22 + 32) = v23;
          *(_QWORD *)(v22 + 40) = v23;
          v24 = *((const void **)v13 - 5);
          if ( v24 )
          {
            *(_QWORD *)(v22 + 16) = v24;
            *(_QWORD *)(v20 + 16) = v24;
            memcpy((void *)(qword_77A0 + v10), v24, *(_QWORD *)(v20 + 32));
          }
          else
          {
            v14 = qword_77A0 + v10;
            *(_QWORD *)(v22 + 16) = qword_77A0 + v10;
            *(_QWORD *)(v20 + 16) = v14;
            v15 = *(_QWORD *)(v20 + 32);
            v16 = *((void (__fastcall **)(__int64, __int64))v13 + 1);
            v17 = qword_77A0 + v10;
            if ( *((_DWORD *)v16 - 1) != -1513466811 )
              __break(0x8228u);
            v16(v17, v15);
          }
          ++v12;
          v13 += 16;
          v18 = qword_77A8 - 2;
          v11 = *(_WORD *)(v3 + 60) + 1;
          v19 = *(_WORD *)(v3 + 56) + 1;
          v10 += *(_QWORD *)(v20 + 32);
          *(_WORD *)(v3 + 60) = v11;
          *(_WORD *)(v3 + 56) = v19;
        }
        while ( v12 < v18 );
      }
    }
  }
  byte_77F8 = 0;
  return 0;
}
