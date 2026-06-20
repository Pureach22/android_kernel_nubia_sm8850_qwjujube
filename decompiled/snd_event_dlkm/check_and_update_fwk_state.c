__int64 check_and_update_fwk_state()
{
  __int64 v0; // x8
  unsigned __int64 *v1; // x9
  unsigned __int64 v2; // x10
  unsigned __int64 v3; // x11
  unsigned __int64 v4; // x12
  int v6; // w13
  char v7; // w14
  int v8; // w13
  unsigned __int64 v9; // x15
  int v10; // w21
  unsigned int v11; // w19
  __int64 v12; // x10
  int v13; // w22
  __int64 v14; // x23
  __int64 (__fastcall *v15)(__int64, __int64); // x9
  __int64 v16; // x0
  __int64 v17; // x1
  unsigned int v18; // w0
  void (__fastcall *v19)(__int64, __int64); // x11
  __int64 v20; // x0
  __int64 v21; // x1
  unsigned __int64 v22; // x10
  int v23; // w19
  _QWORD *v24; // x10
  void (__fastcall *v25)(__int64, __int64); // x9
  __int64 v26; // x0
  __int64 v27; // x1
  __int64 (__fastcall *v28)(__int64, __int64); // x9
  __int64 v29; // x0
  __int64 v30; // x1
  unsigned int v31; // w0
  __int64 v32; // x8
  __int64 v33; // x21
  __int64 v34; // x22
  _QWORD *v35; // x10
  void (__fastcall *v36)(__int64, __int64); // x9
  __int64 v37; // x0
  __int64 v38; // x1
  __int64 *v39; // x15
  char v40; // w14
  unsigned __int64 v41; // x17
  char v42; // w16
  __int64 v43; // x0
  __int64 v44; // t1

  v0 = master;
  v1 = *(unsigned __int64 **)(master + 32);
  v2 = *v1;
  if ( !*v1 )
  {
    v7 = 1;
    goto LABEL_13;
  }
  v3 = v1[1];
  v4 = v2 - 1;
  if ( v2 == 1 )
    goto LABEL_8;
  if ( (unsigned int)v4 > 0x7FFFFFFE || v4 >> 31 != 0 )
  {
    v4 = 0;
LABEL_8:
    v6 = 0;
    v7 = 1;
LABEL_9:
    v8 = v6 + 1;
    do
    {
      v9 = v3 + 32 * v4;
      v4 = v8++;
      v7 &= *(_BYTE *)(*(_QWORD *)(v9 + 8) + 41LL);
    }
    while ( v2 > v4 );
    goto LABEL_13;
  }
  v4 = *v1 & 0xFFFFFFFE;
  v39 = (__int64 *)(v3 + 40);
  v40 = 1;
  v6 = v2 & 0xFFFFFFFE;
  v41 = v4;
  v42 = 1;
  do
  {
    v43 = *(v39 - 4);
    v44 = *v39;
    v39 += 8;
    v41 -= 2LL;
    v40 &= *(_BYTE *)(v43 + 41);
    v42 &= *(_BYTE *)(v44 + 41);
  }
  while ( v41 );
  v7 = v42 & v40;
  if ( v2 != v4 )
    goto LABEL_9;
LABEL_13:
  v10 = (unsigned __int8)(v7 & *(_BYTE *)(master + 24));
  if ( *(unsigned __int8 *)(master + 25) == v10 )
    return 0;
  if ( ((unsigned __int8)v7 & *(_BYTE *)(master + 24)) == 0 )
  {
    v19 = *(void (__fastcall **)(__int64, __int64))(*(_QWORD *)(master + 8) + 8LL);
    if ( v19 )
    {
      v20 = *(_QWORD *)master;
      v21 = *(_QWORD *)(master + 16);
      if ( *((_DWORD *)v19 - 1) != -501421344 )
        __break(0x822Bu);
      v19(v20, v21);
      v0 = master;
      v1 = *(unsigned __int64 **)(master + 32);
      v2 = *v1;
    }
    if ( v2 )
    {
      v22 = 0;
      v23 = 1;
      do
      {
        v24 = *(_QWORD **)(v1[1] + 32 * v22 + 8);
        v25 = *(void (__fastcall **)(__int64, __int64))(v24[3] + 8LL);
        if ( v25 )
        {
          v26 = v24[2];
          v27 = v24[4];
          if ( *((_DWORD *)v25 - 1) != -501421344 )
            __break(0x8229u);
          v25(v26, v27);
          v0 = master;
        }
        v1 = *(unsigned __int64 **)(v0 + 32);
        v22 = v23++;
      }
      while ( *v1 > v22 );
    }
    goto LABEL_56;
  }
  if ( v2 )
  {
    v12 = 0;
    v13 = 0;
    do
    {
      v14 = *(_QWORD *)(v1[1] + 32 * v12 + 8);
      v15 = **(__int64 (__fastcall ***)(__int64, __int64))(v14 + 24);
      if ( v15 )
      {
        v16 = *(_QWORD *)(v14 + 16);
        v17 = *(_QWORD *)(v14 + 32);
        if ( *((_DWORD *)v15 - 1) != 848979900 )
          __break(0x8229u);
        v18 = v15(v16, v17);
        if ( v18 )
        {
          v11 = v18;
          if ( (unsigned int)__ratelimit(&check_and_update_fwk_state__rs, "check_and_update_fwk_state") )
            dev_err(*(_QWORD *)(v14 + 16), "%s: enable failed\n", "check_and_update_fwk_state");
          goto LABEL_44;
        }
        v0 = master;
      }
      v1 = *(unsigned __int64 **)(v0 + 32);
      v12 = ++v13;
    }
    while ( *v1 > v13 );
  }
  v28 = **(__int64 (__fastcall ***)(__int64, __int64))(v0 + 8);
  if ( !v28 )
    goto LABEL_56;
  v29 = *(_QWORD *)v0;
  v30 = *(_QWORD *)(v0 + 16);
  if ( *((_DWORD *)v28 - 1) != 848979900 )
    __break(0x8229u);
  v31 = v28(v29, v30);
  if ( !v31 )
  {
    v0 = master;
LABEL_56:
    v11 = 0;
    *(_BYTE *)(v0 + 25) = v10;
    return v11;
  }
  v11 = v31;
  if ( (unsigned int)__ratelimit(&check_and_update_fwk_state__rs_16, "check_and_update_fwk_state") )
    dev_err(*(_QWORD *)master, "%s: enable failed\n", "check_and_update_fwk_state");
  v13 = **(_DWORD **)(master + 32);
LABEL_44:
  if ( v13 >= 1 )
  {
    v32 = master;
    v33 = (unsigned int)v13 + 1LL;
    v34 = 32LL * (unsigned int)v13 - 24;
    do
    {
      v35 = *(_QWORD **)(*(_QWORD *)(*(_QWORD *)(v32 + 32) + 8LL) + v34);
      v36 = *(void (__fastcall **)(__int64, __int64))(v35[3] + 8LL);
      if ( v36 )
      {
        v37 = v35[2];
        v38 = v35[4];
        if ( *((_DWORD *)v36 - 1) != -501421344 )
          __break(0x8229u);
        v36(v37, v38);
        v32 = master;
      }
      --v33;
      v34 -= 32;
    }
    while ( v33 > 1 );
  }
  return v11;
}
