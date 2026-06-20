__int64 ipa_drop_stats_init()
{
  __int64 ep_mapping; // x0
  unsigned int v1; // w20
  unsigned int ep_reg_idx; // w19
  int ep_bit; // w0
  int v4; // w20
  __int64 v5; // x8
  __int64 v6; // x0
  unsigned int v7; // w20
  int v8; // w0
  unsigned int v9; // w8
  __int64 v10; // x0
  unsigned int v11; // w20
  int v12; // w0
  __int64 v13; // x0
  unsigned int v14; // w20
  int v15; // w0
  int v16; // w20
  __int64 v17; // x0
  unsigned int v18; // w20
  int v19; // w0
  __int64 v20; // x9
  __int64 v21; // x0
  unsigned int v22; // w20
  int v23; // w0
  __int64 v24; // x10
  __int64 v25; // x0
  unsigned int v26; // w20
  int v27; // w0
  __int64 v28; // x0
  unsigned int v29; // w20
  __int64 result; // x0
  _QWORD v31[2]; // [xsp+0h] [xbp-10h] BYREF

  v31[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v31[0] = 0;
  ep_mapping = ipa_get_ep_mapping(19);
  if ( (_DWORD)ep_mapping == -1 )
  {
    ep_reg_idx = 0;
    v4 = 0;
  }
  else
  {
    v1 = ep_mapping;
    ep_reg_idx = ipahal_get_ep_reg_idx(ep_mapping);
    ep_bit = ipahal_get_ep_bit(v1);
    if ( ep_reg_idx > 1 )
      goto LABEL_45;
    v4 = *((_DWORD *)v31 + ep_reg_idx) | ep_bit;
  }
  v5 = ipa3_ctx;
  *((_DWORD *)v31 + ep_reg_idx) = v4;
  if ( *(_DWORD *)(v5 + 50148) || *(_BYTE *)(v5 + 34904) == 1 )
  {
    v6 = ipa_get_ep_mapping(13);
    if ( (_DWORD)v6 == -1 )
    {
      v8 = 0;
    }
    else
    {
      v7 = v6;
      ep_reg_idx = ipahal_get_ep_reg_idx(v6);
      v8 = ipahal_get_ep_bit(v7);
      if ( ep_reg_idx > 1 )
        goto LABEL_45;
      v4 = *((_DWORD *)v31 + ep_reg_idx);
    }
    v5 = ipa3_ctx;
    *((_DWORD *)v31 + ep_reg_idx) = v4 | v8;
  }
  if ( *(_DWORD *)(v5 + 32256) )
  {
    v9 = *(_DWORD *)(v5 + 32240);
    if ( v9 <= 0x14 )
    {
      v10 = ipa_get_ep_mapping(27);
      if ( (_DWORD)v10 == -1 )
      {
        v12 = 0;
      }
      else
      {
        v11 = v10;
        ep_reg_idx = ipahal_get_ep_reg_idx(v10);
        v12 = ipahal_get_ep_bit(v11);
        if ( ep_reg_idx > 1 )
          goto LABEL_45;
      }
      v16 = *((_DWORD *)v31 + ep_reg_idx) | v12;
      *((_DWORD *)v31 + ep_reg_idx) = v16;
      v17 = ipa_get_ep_mapping(83);
      if ( (_DWORD)v17 == -1 )
      {
        v19 = 0;
      }
      else
      {
        v18 = v17;
        ep_reg_idx = ipahal_get_ep_reg_idx(v17);
        v19 = ipahal_get_ep_bit(v18);
        if ( ep_reg_idx > 1 )
          goto LABEL_45;
        v16 = *((_DWORD *)v31 + ep_reg_idx);
      }
      v20 = ipa3_ctx;
      *((_DWORD *)v31 + ep_reg_idx) = v16 | v19;
      v9 = *(_DWORD *)(v20 + 32240);
    }
    if ( v9 >= 0x17 )
    {
      v21 = ipa_get_ep_mapping(35);
      if ( (_DWORD)v21 == -1 )
      {
        v23 = 0;
      }
      else
      {
        v22 = v21;
        ep_reg_idx = ipahal_get_ep_reg_idx(v21);
        v23 = ipahal_get_ep_bit(v22);
        if ( ep_reg_idx > 1 )
          goto LABEL_45;
      }
      v24 = ipa3_ctx;
      *((_DWORD *)v31 + ep_reg_idx) |= v23;
      if ( *(_DWORD *)(v24 + 32240) >= 0x18u )
      {
        v25 = ipa_get_ep_mapping(95);
        if ( (_DWORD)v25 != -1 )
        {
          v26 = v25;
          ep_reg_idx = ipahal_get_ep_reg_idx(v25);
          v27 = ipahal_get_ep_bit(v26);
          if ( ep_reg_idx <= 1 )
            goto LABEL_41;
LABEL_45:
          __break(0x5512u);
        }
        v27 = 0;
LABEL_41:
        *((_DWORD *)v31 + ep_reg_idx) |= v27;
      }
    }
  }
  else
  {
    if ( *(_DWORD *)(v5 + 50144) )
    {
      v13 = ipa_get_ep_mapping(119);
      if ( (_DWORD)v13 == -1 )
      {
        v15 = 0;
      }
      else
      {
        v14 = v13;
        ep_reg_idx = ipahal_get_ep_reg_idx(v13);
        v15 = ipahal_get_ep_bit(v14);
        if ( ep_reg_idx > 1 )
          goto LABEL_45;
      }
      v5 = ipa3_ctx;
      *((_DWORD *)v31 + ep_reg_idx) |= v15;
    }
    if ( *(_BYTE *)(v5 + 51105) == 1 )
    {
      v28 = ipa_get_ep_mapping(125);
      if ( (_DWORD)v28 == -1 )
      {
        v27 = 0;
      }
      else
      {
        v29 = v28;
        ep_reg_idx = ipahal_get_ep_reg_idx(v28);
        v27 = ipahal_get_ep_bit(v29);
        if ( ep_reg_idx > 1 )
          goto LABEL_45;
      }
      goto LABEL_41;
    }
  }
  result = ipa_init_drop_stats(v31);
  _ReadStatusReg(SP_EL0);
  return result;
}
