void __fastcall gsi_process_evt_re(__int64 a1, __int64 a2, char a3)
{
  __int64 v4; // x9
  __int64 v5; // x21
  unsigned int v6; // w4
  unsigned __int64 v7; // x8
  __int64 v8; // x22
  int v9; // w8
  __int64 v10; // x22
  int v11; // t1
  unsigned __int64 v13; // x4
  char v14; // w8
  unsigned __int64 v15; // x10
  unsigned __int64 v16; // x11
  bool v17; // cc
  unsigned int v18; // w8
  unsigned int v19; // w9
  unsigned __int64 v20; // x9
  __int64 v21; // x10
  unsigned __int64 v22; // x8
  __int64 v23; // x10
  __int64 v24; // x10
  void (__fastcall *v25)(_QWORD); // x8
  __int64 v26; // x8
  __int64 v27; // x8
  __int64 v28; // x9
  __int64 v29; // x10
  __int64 v30; // x8
  __int64 v31; // x23
  char v32; // w22

  __dmb(1u);
  v4 = gsi_ctx;
  v5 = *(_QWORD *)(a1 + 184) + *(_QWORD *)(a1 + 144) - *(_QWORD *)(a1 + 152);
  v6 = *(unsigned __int8 *)(v5 + 15);
  v7 = *(unsigned int *)(gsi_ctx + 28608);
  if ( (unsigned int)v7 <= v6 )
  {
    __break(0x800u);
    v32 = a3;
    dev_err(*(_QWORD *)(gsi_ctx + 8), "%s:%d Unexpected ch %d\n", "gsi_process_chan", 686, v6);
    a3 = v32;
LABEL_25:
    v7 = *(unsigned __int8 *)(v5 + 15);
    if ( v7 < 0x25 )
    {
      if ( (a3 & 1) == 0 )
        goto LABEL_46;
LABEL_42:
      v26 = gsi_ctx + 448LL * (unsigned int)v7 + 184;
      if ( !*(_DWORD *)(v26 + 4) || (*(_BYTE *)(v26 + 81) & 1) != 0 )
        return;
      goto LABEL_46;
    }
    goto LABEL_53;
  }
  if ( v6 >= 0x25 )
    goto LABEL_53;
  v8 = gsi_ctx + 448LL * *(unsigned __int8 *)(v5 + 15);
  v11 = *(_DWORD *)(v8 + 184);
  v10 = v8 + 184;
  v9 = v11;
  if ( v11 != 2 && v9 != 5 )
  {
    __break(0x800u);
    goto LABEL_25;
  }
  v13 = *(_QWORD *)v5;
  if ( *(_BYTE *)(v5 + 14) == 40 )
  {
    v14 = *(_BYTE *)(v5 + 10);
  }
  else
  {
    v7 = *(_QWORD *)(v10 + 176);
    if ( v13 != v7 )
    {
      v15 = *(_QWORD *)(v10 + 144);
      if ( v15 > v7 )
        goto LABEL_54;
      v16 = *(_QWORD *)(v10 + 192);
      if ( v16 <= v7 )
        goto LABEL_54;
      if ( v15 > v13 || v16 <= v13 )
      {
LABEL_55:
        dev_err(*(_QWORD *)(v4 + 8), "%s:%d address = 0x%llx not in range\n", "gsi_get_complete_num", 665, v13);
        __break(0x800u);
        JUMPOUT(0x21DD0);
      }
      v17 = v13 > v7;
      v18 = v13 - v7;
      if ( !v17 )
        v18 += *(_DWORD *)(v10 + 184);
      v19 = *(unsigned __int8 *)(v10 + 188);
      *(_QWORD *)(v10 + 176) = v13;
      *(_QWORD *)(v10 + 336) += (unsigned __int16)(v18 / v19);
    }
    if ( (a3 & 1) == 0 || (v20 = v13, *(_DWORD *)(v10 + 4) == 1) && (v20 = v13, (*(_BYTE *)(v10 + 81) & 1) == 0) )
    {
      v21 = *(_QWORD *)(v10 + 192);
      v20 = v13 + *(unsigned __int8 *)(v10 + 188);
      *(_QWORD *)(v10 + 176) = v20;
      if ( v20 == v21 )
      {
        v20 = *(_QWORD *)(v10 + 144);
        *(_QWORD *)(v10 + 176) = v20;
      }
    }
    v22 = *(_QWORD *)(v10 + 144);
    *(_QWORD *)(v10 + 160) = v20;
    if ( v22 > v13 || *(_QWORD *)(v10 + 192) <= v13 )
    {
      __break(0x800u);
      v22 = *(_QWORD *)(v10 + 144);
    }
    LODWORD(v13) = ((int)v13 - (int)v22) / (unsigned int)*(unsigned __int8 *)(v10 + 188);
    v14 = 16;
  }
  *(_BYTE *)(a2 + 22) = v14;
  v23 = *(_QWORD *)(v10 + 200);
  if ( (*(_BYTE *)(v23 + 16LL * (unsigned __int16)v13) & 1) == 0 )
  {
    __break(0x800u);
    v23 = *(_QWORD *)(v10 + 200);
  }
  *(_QWORD *)(a2 + 8) = *(_QWORD *)(v23 + 16LL * (unsigned __int16)v13 + 8);
  if ( (a3 & 1) != 0 && (*(_DWORD *)(v10 + 4) != 1 || *(_BYTE *)(v10 + 81) == 1) )
  {
    *(_QWORD *)a2 = *(_QWORD *)(v10 + 112);
    *(_DWORD *)(a2 + 16) = *(unsigned __int8 *)(v5 + 11);
    *(_WORD *)(a2 + 20) = *(_WORD *)(v5 + 8);
    goto LABEL_37;
  }
  v24 = *(_QWORD *)(v10 + 200);
  v4 = *(_QWORD *)(v10 + 336) + 1LL;
  *(_QWORD *)(v10 + 336) = v4;
  *(_BYTE *)(v24 + 16LL * (unsigned __int16)v13) = 0;
  *(_QWORD *)a2 = *(_QWORD *)(v10 + 112);
  *(_DWORD *)(a2 + 16) = *(unsigned __int8 *)(v5 + 11);
  *(_WORD *)(a2 + 20) = *(_WORD *)(v5 + 8);
  if ( (a3 & 1) != 0 )
  {
LABEL_37:
    if ( *(_DWORD *)(v10 + 300) )
    {
      v31 = a2;
      dev_err(*(_QWORD *)(gsi_ctx + 8), "%s:%d Calling client callback in polling mode\n", "gsi_process_chan", 744);
      a2 = v31;
      __break(0x800u);
    }
    v25 = *(void (__fastcall **)(_QWORD))(v10 + 88);
    if ( *((_DWORD *)v25 - 1) != 1558426112 )
      __break(0x8228u);
    v25(a2);
    v7 = *(unsigned __int8 *)(v5 + 15);
    if ( v7 <= 0x24 )
      goto LABEL_42;
    goto LABEL_53;
  }
  v7 = *(unsigned __int8 *)(v5 + 15);
  if ( (unsigned int)v7 >= 0x25 )
  {
LABEL_53:
    __break(0x5512u);
LABEL_54:
    dev_err(*(_QWORD *)(v4 + 8), "%s:%d address = 0x%llx not in range\n", "gsi_get_complete_num", 660, v7);
    __break(0x800u);
    goto LABEL_55;
  }
LABEL_46:
  v27 = *(unsigned __int8 *)(a1 + 196);
  v28 = *(_QWORD *)(a1 + 200);
  v29 = *(_QWORD *)(a1 + 184) + v27;
  *(_QWORD *)(a1 + 184) = v29;
  if ( v29 == v28 )
    *(_QWORD *)(a1 + 184) = *(_QWORD *)(a1 + 152);
  v30 = *(_QWORD *)(a1 + 176) + v27;
  *(_QWORD *)(a1 + 176) = v30;
  if ( v30 == v28 )
    *(_QWORD *)(a1 + 176) = *(_QWORD *)(a1 + 152);
  ++*(_QWORD *)(a1 + 320);
}
