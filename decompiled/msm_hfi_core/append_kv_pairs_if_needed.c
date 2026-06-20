__int64 __fastcall append_kv_pairs_if_needed(__int64 a1, _DWORD *a2)
{
  __int64 v2; // x30
  __int64 v5; // x20
  __int64 v6; // x3
  __int64 v7; // x4
  __int64 v8; // x4
  __int64 v9; // x8
  __int64 *v10; // x10
  __int64 v11; // x13
  int v12; // w14
  int v13; // w12
  __int64 v14; // x13
  unsigned int v15; // w5
  unsigned int v16; // w6
  __int64 v17; // x3
  unsigned int appended; // w0
  __int64 v19; // x3
  __int64 v20; // x4
  __int64 result; // x0
  unsigned int v22; // w24
  unsigned int v23; // w25
  __int64 v24; // x4
  unsigned int v25; // w19
  _QWORD s[61]; // [xsp+8h] [xbp-1E8h] BYREF

  v5 = v2;
  s[60] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(s, 0, 0x1E0u);
  if ( (~msm_hfi_core_debug_level & 0x10001) != 0 )
  {
    if ( !a1 )
    {
LABEL_20:
      printk(&unk_1905C, "append_kv_pairs_if_needed", 2462, v5, v7);
      result = 4294967274LL;
      goto LABEL_18;
    }
  }
  else
  {
    printk(&unk_1E83A, "append_kv_pairs_if_needed", 2459, v6, v7);
    if ( !a1 )
      goto LABEL_20;
  }
  if ( !a2 )
    goto LABEL_20;
  v8 = (unsigned int)*a2;
  if ( (unsigned int)(v8 - 50331649) >= 3 )
  {
    printk(&unk_1DE25, "append_kv_pairs_if_needed", 2469, v5, v8);
  }
  else
  {
    if ( (_DWORD)v8 == 50331649 )
    {
      v17 = 50331649;
      LODWORD(s[0]) = 17039361;
      v15 = 1;
      v16 = 8;
      s[1] = &panel_caps_payload;
    }
    else if ( (_DWORD)v8 == 50331650 )
    {
      s[1] = &panel_tm_payload;
      v15 = 8;
      LODWORD(s[0]) = 17039362;
      v16 = 180;
      s[3] = &unk_378;
      LODWORD(s[4]) = 17039364;
      s[5] = &unk_380;
      LODWORD(s[6]) = 33816582;
      s[7] = &unk_384;
      LODWORD(s[2]) = 33816579;
      LODWORD(s[8]) = 235143173;
      s[9] = &unk_38C;
      LODWORD(s[14]) = 17039369;
      LODWORD(s[10]) = 201342983;
      s[11] = &unk_3C4;
      s[13] = &unk_3F4;
      LODWORD(s[12]) = 67371016;
      s[15] = &unk_404;
      v17 = 50331650;
    }
    else
    {
      v9 = 0;
      s[1] = &panel_gen_payload;
      LODWORD(s[0]) = 17039371;
      v10 = &s[3];
      do
      {
        v11 = *(unsigned int *)((char *)&panel_gen_sizes + v9);
        v12 = *(_DWORD *)((char *)&panel_gen_sizes + v9 + 4);
        v13 = *(_DWORD *)((char *)&panel_gen_keys + v9 + 4);
        v9 += 4;
        v14 = *(v10 - 2) + 4 * v11;
        *((_DWORD *)v10 - 2) = v13 | (v12 << 24);
        *v10 = v14;
        v10 += 2;
      }
      while ( v9 != 88 );
      v15 = 23;
      v16 = 192;
      v17 = 50331651;
    }
    if ( (~msm_hfi_core_debug_level & 0x10001) == 0 )
    {
      v22 = v15;
      v23 = v16;
      printk(&unk_1F641, "append_kv_pairs_if_needed", 2521, v17, v15);
      LODWORD(v17) = *a2;
      v15 = v22;
      v16 = v23;
    }
    appended = hfi_append_packet_with_kv_pairs(a1, v17, 2, 0, (unsigned int *)s, v15, v16);
    if ( appended )
    {
      v24 = (unsigned int)*a2;
      v25 = appended;
      printk(&unk_1ED35, "append_kv_pairs_if_needed", 2526, v5, v24);
      result = v25;
      goto LABEL_18;
    }
    if ( (~msm_hfi_core_debug_level & 0x10001) == 0 )
      printk(&unk_1C28B, "append_kv_pairs_if_needed", 2530, v19, v20);
  }
  result = 0;
LABEL_18:
  _ReadStatusReg(SP_EL0);
  return result;
}
