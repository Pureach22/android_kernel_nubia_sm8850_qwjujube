__int64 __fastcall msm_vidc_update_buffer_count(__int64 result, int a2)
{
  __int64 v2; // x20
  __int64 v3; // x8
  unsigned int (*v4)(void); // x8
  __int64 v5; // x19
  __int64 v6; // x4
  __int64 v7; // x8
  __int64 v8; // x19
  __int64 v9; // x8
  __int64 (*v10)(void); // x8
  __int64 v11; // x19
  int v12; // w0
  int v13; // w5
  unsigned int v14; // w6
  unsigned __int64 v15; // x11
  _BYTE *v16; // x8
  bool v17; // w12
  bool v18; // cf
  int v19; // w8
  int v20; // w9
  unsigned int v21; // w8
  void *v22; // x8
  __int64 v23; // x8
  __int64 (*v24)(void); // x8
  __int64 v25; // x19
  int v26; // w5
  unsigned int v27; // w6
  unsigned __int64 v28; // x11
  _BYTE *v29; // x9
  bool v30; // w13
  int v31; // w8
  int v32; // w9
  unsigned int v33; // w8

  v2 = *(_QWORD *)(result + 320);
  if ( a2 == 1 )
  {
    if ( (*(_WORD *)(*(_QWORD *)(result + 1840) + 320LL) & 1) == 0 )
    {
      if ( v2 )
      {
        v7 = *(_QWORD *)(v2 + 6560);
        if ( v7 )
        {
          v7 = *(_QWORD *)(v7 + 56);
          if ( v7 )
          {
            v8 = result;
            if ( *(_DWORD *)(v7 - 4) != 1958436756 )
              __break(0x8228u);
            LODWORD(v7) = ((__int64 (*)(void))v7)();
            result = v8;
          }
        }
      }
      else
      {
        LODWORD(v7) = 0;
      }
      *(_DWORD *)(result + 2560) = v7;
    }
    if ( v2 && (v23 = *(_QWORD *)(v2 + 6560)) != 0 && (v24 = *(__int64 (**)(void))(v23 + 64)) != nullptr )
    {
      v25 = result;
      if ( *((_DWORD *)v24 - 1) != 1958436756 )
        __break(0x8228u);
      v26 = v24();
      result = v25;
    }
    else
    {
      v26 = 0;
    }
    v6 = *(unsigned int *)(result + 2560);
    v27 = *(_DWORD *)(result + 2568);
    *(_DWORD *)(result + 2564) = v26;
    if ( v27 < (int)v6 + v26 )
    {
      v27 = v6 + v26;
      *(_DWORD *)(result + 2568) = v6 + v26;
    }
    v28 = 1;
    v29 = (_BYTE *)(result + 4536);
    v30 = 1;
    do
    {
      if ( (*v29 & 0x80) != 0
        && ((~*((_DWORD *)v29 - 4) & 0x11LL) == 0
         || (*((_QWORD *)v29 - 2) & 5LL) == 5
         || (*((_QWORD *)v29 - 2) & 0x24LL) == 0x24) )
      {
        break;
      }
      v18 = v28++ >= 0xC4;
      v29 += 168;
      v30 = !v18;
    }
    while ( v28 != 197 );
    if ( v30 )
      v31 = v6;
    else
      v31 = 0;
    if ( v30 )
      v32 = v26;
    else
      v32 = 0;
    *(_DWORD *)(result + 2680) = v31;
    if ( v30 )
      v33 = v27;
    else
      v33 = 0;
    *(_DWORD *)(result + 2684) = v32;
    *(_DWORD *)(result + 2688) = v33;
    if ( result )
    {
      if ( (msm_vidc_debug & 2) != 0 )
      {
        v22 = &unk_8433A;
        goto LABEL_84;
      }
      return 0;
    }
  }
  else if ( a2 )
  {
    if ( (msm_vidc_debug & 1) != 0 )
      printk(&unk_875B8, "err ", 0xFFFFFFFFLL, "codec", "msm_vidc_update_buffer_count");
    return 4294967274LL;
  }
  else
  {
    if ( v2 )
    {
      v3 = *(_QWORD *)(v2 + 6560);
      if ( v3 && (v4 = *(unsigned int (**)(void))(v3 + 56)) != nullptr )
      {
        v5 = result;
        if ( *((_DWORD *)v4 - 1) != 1958436756 )
          __break(0x8228u);
        v6 = v4();
        result = v5;
      }
      else
      {
        v6 = 0;
      }
      *(_DWORD *)(result + 2520) = v6;
      v9 = *(_QWORD *)(v2 + 6560);
      if ( v9 && (v10 = *(__int64 (**)(void))(v9 + 64)) != nullptr )
      {
        v11 = result;
        if ( *((_DWORD *)v10 - 1) != 1958436756 )
          __break(0x8228u);
        v12 = v10();
        v6 = *(unsigned int *)(v11 + 2520);
        v13 = v12;
        result = v11;
      }
      else
      {
        v13 = 0;
      }
    }
    else
    {
      v6 = 0;
      v13 = 0;
      *(_DWORD *)(result + 2520) = 0;
    }
    v14 = *(_DWORD *)(result + 2528);
    *(_DWORD *)(result + 2524) = v13;
    if ( v14 < (int)v6 + v13 )
    {
      v14 = v6 + v13;
      *(_DWORD *)(result + 2528) = v6 + v13;
    }
    v15 = 1;
    v16 = (_BYTE *)(result + 4536);
    v17 = 1;
    do
    {
      if ( (*v16 & 0x80) != 0
        && ((~*((_DWORD *)v16 - 4) & 9LL) == 0
         || (*((_QWORD *)v16 - 2) & 3LL) == 3
         || (*((_QWORD *)v16 - 2) & 0x22LL) == 0x22) )
      {
        break;
      }
      v18 = v15++ >= 0xC4;
      v16 += 168;
      v17 = !v18;
    }
    while ( v15 != 197 );
    if ( v17 )
      v19 = v6;
    else
      v19 = 0;
    if ( v17 )
      v20 = v13;
    else
      v20 = 0;
    *(_DWORD *)(result + 2640) = v19;
    if ( v17 )
      v21 = v14;
    else
      v21 = 0;
    *(_DWORD *)(result + 2644) = v20;
    *(_DWORD *)(result + 2648) = v21;
    if ( result )
    {
      if ( (msm_vidc_debug & 2) != 0 )
      {
        v22 = &unk_8D92E;
LABEL_84:
        printk(v22, "high", result + 340, "msm_vidc_update_buffer_count", v6);
        return 0;
      }
      return 0;
    }
  }
  return result;
}
