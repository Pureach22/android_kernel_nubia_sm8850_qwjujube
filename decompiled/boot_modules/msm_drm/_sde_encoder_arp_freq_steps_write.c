unsigned __int64 __fastcall sde_encoder_arp_freq_steps_write(__int64 a1, __int64 a2, unsigned __int64 a3)
{
  char v3; // w23
  unsigned int v4; // w24
  unsigned int v5; // w25
  __int64 v6; // x8
  size_t v7; // x20
  _QWORD *v8; // x22
  unsigned __int64 v9; // x19
  _DWORD *v12; // x20
  int v13; // w8
  int v14; // w8
  __int64 *v15; // x8
  __int64 v16; // x0
  __int64 v17; // x9
  int v18; // w10
  __int64 *v19; // x12
  int v20; // w13
  unsigned int v21; // w14
  unsigned int v22; // w15
  unsigned __int64 StatusReg; // x26
  __int64 v24; // x27
  char s[257]; // [xsp+7h] [xbp-109h] BYREF
  __int64 v26; // [xsp+108h] [xbp-8h]

  v6 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a3 >= 0x200 )
    v7 = 512;
  else
    v7 = a3;
  v26 = v6;
  if ( !a1 )
    goto LABEL_8;
  v8 = *(_QWORD **)(a1 + 32);
  if ( !v8 )
    goto LABEL_8;
  v9 = a3;
  memset(s, 0, sizeof(s));
  if ( v9 >= 0x102 )
  {
    _copy_overflow(257, v7);
    v9 = -22;
    goto LABEL_9;
  }
  _check_object_size(s, v7, 0);
  if ( inline_copy_from_user_3((int)s, a2, v7) )
  {
LABEL_8:
    v9 = -22;
    goto LABEL_9;
  }
  if ( v9 == 257 )
  {
    __break(0x5512u);
    StatusReg = _ReadStatusReg(SP_EL0);
    v24 = *(_QWORD *)(StatusReg + 80);
    *(_QWORD *)(StatusReg + 80) = &sde_encoder_parse_freq_step_table__alloc_tag;
    v12 = (_DWORD *)_kmalloc_noprof((unsigned int)(24 * a2), 3520);
    *(_QWORD *)(StatusReg + 80) = v24;
    if ( v12 )
      goto LABEL_25;
LABEL_47:
    printk(&unk_22ADAE, "_sde_encoder_parse_freq_step_table");
    goto LABEL_9;
  }
  s[v7] = 0;
  if ( sscanf(
         s,
         "%u %u %u %u %u",
         &sde_encoder_arp_freq_steps_write_freq_patterrn_arr32,
         &dword_293BDC,
         &dword_293BE0,
         &dword_293BE4,
         &dword_293BE8) >= 6 )
  {
    printk(&unk_268EFA, "_sde_encoder_arp_freq_steps_write");
    v9 = -14;
    goto LABEL_9;
  }
  v8[612] = &sde_encoder_arp_freq_steps_write_freq_patterrn_arr32;
  v4 = sde_encoder_arp_freq_steps_write_freq_patterrn_arr32;
  if ( sde_encoder_arp_freq_steps_write_freq_patterrn_arr32 )
  {
    if ( dword_293BDC )
    {
      if ( dword_293BE0 )
      {
        if ( dword_293BE4 )
        {
          v3 = 0;
          if ( dword_293BE8 )
            v5 = 5;
          else
            v5 = 4;
        }
        else
        {
          v3 = 0;
          v5 = 3;
        }
      }
      else
      {
        v3 = 0;
        v5 = 2;
      }
    }
    else
    {
      v3 = 1;
      v5 = 1;
    }
  }
  else
  {
    v5 = 0;
    v3 = 1;
  }
  v12 = (_DWORD *)v8[613];
  a2 = v5 >> 1;
  if ( v12 )
    goto LABEL_26;
  v12 = (_DWORD *)_kmalloc_noprof((unsigned int)(24 * a2), 3520);
  if ( !v12 )
    goto LABEL_47;
LABEL_25:
  v8[613] = v12;
LABEL_26:
  *(_DWORD *)(v8[600] + 8LL) = a2;
  if ( v4 )
  {
    v12[3] = *(_DWORD *)v8[612];
    v4 = *(_DWORD *)(v8[612] + 4LL);
    v12[4] = v4;
    if ( v5 < 3 )
    {
      v12 += 6;
    }
    else
    {
      v12[9] = *(_DWORD *)(v8[612] + 8LL);
      v13 = *(_DWORD *)(v8[612] + 12LL);
      v4 += v13;
      v12[10] = v13;
      if ( v5 < 5 )
      {
        v12 += 12;
      }
      else
      {
        v12[15] = *(_DWORD *)(v8[612] + 16LL);
        v14 = *(_DWORD *)(v8[612] + 20LL);
        v12[16] = v14;
        v4 += v14;
        v12 += 18;
      }
    }
  }
  v15 = (__int64 *)v8[613];
  v16 = *v15;
  if ( !*v15 )
  {
    v16 = _kmalloc_noprof(4LL * v4, 3520);
    if ( !v16 )
    {
      kfree(v12);
      v8[613] = 0;
      printk(&unk_227388, "_sde_encoder_parse_freq_step_table");
      goto LABEL_9;
    }
    v15 = (__int64 *)v8[613];
  }
  if ( (v3 & 1) == 0 )
  {
    v17 = 0;
    v18 = 0;
    do
    {
      v19 = &v15[3 * v17];
      if ( *((_DWORD *)v19 + 4) )
      {
        v20 = *((_DWORD *)v19 + 3);
        v21 = 0;
        do
        {
          v22 = v18 + v21++;
          *(_DWORD *)(v16 + 4LL * v22) = v20;
        }
        while ( v21 < *((_DWORD *)v19 + 4) );
        v18 += v21;
      }
      ++v17;
    }
    while ( v17 != a2 );
    v15 = (__int64 *)v8[613];
  }
  *v15 = v16;
  *(_DWORD *)(v8[613] + 20LL) = 0;
  *(_DWORD *)(v8[613] + 8LL) = v4;
LABEL_9:
  _ReadStatusReg(SP_EL0);
  return v9;
}
