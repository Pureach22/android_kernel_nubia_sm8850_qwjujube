__int64 __fastcall dp_ipa_handle_rx_buf_pool_smmu_mapping(__int64 a1, char a2, char a3, __int64 a4, __int64 a5, int a6)
{
  __int64 result; // x0
  unsigned __int64 StatusReg; // x8
  unsigned __int64 v12; // x8
  int v13; // w27
  unsigned int v14; // w26
  unsigned int v15; // w28
  int v16; // w20
  _BYTE *v17; // x0
  __int64 v18; // x1
  unsigned int v19; // w8
  _BYTE *v20; // x21
  __int64 v21; // x8
  __int64 v22; // x8

  result = ipa_is_ready();
  if ( (result & 1) == 0 || *(_BYTE *)(*(_QWORD *)(a1 + 24) + 608LL) != 1 )
    return result;
  dp_rx_set_reo_ctx_mapping_lock_required_0(a1, 1);
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(a1 + 12472);
  }
  else
  {
    raw_spin_lock_bh(a1 + 12472);
    *(_QWORD *)(a1 + 12480) |= 1uLL;
  }
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (v12 = _ReadStatusReg(SP_EL0), (*(_DWORD *)(v12 + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(v12 + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(a1 + 18520);
    v13 = *(_DWORD *)(a1 + 12416);
    if ( v13 )
    {
LABEL_11:
      v14 = *(unsigned __int16 *)(a1 + 12424);
      v15 = 0;
      if ( (a2 & 1) != 0 )
        v16 = 256;
      else
        v16 = 0;
      do
      {
        if ( !*(_QWORD *)(a1 + 12440) )
          break;
        v17 = (_BYTE *)dp_rx_desc_find(v15 / v14, v15 % v14, a1 + 12416);
        if ( (v17[30] & 3) == 1 && ((v17[30] & 0x20) == 0 || (a3 & 1) != 0) )
        {
          v18 = *(_QWORD *)v17;
          if ( ((*(_DWORD *)(*(_QWORD *)v17 + 48LL) & 0x100) == 0) == (a2 & 1) )
          {
            v19 = *(_DWORD *)(*(_QWORD *)v17 + 48LL) & 0xFFFFFEFF | v16;
            *(_DWORD *)(v18 + 48) = v19;
            if ( (a2 & 1) != 0 )
            {
              *(_DWORD *)(v18 + 48) = v19 & 0x3FFFFFF | (a6 << 26);
              _dp_ipa_handle_buf_smmu_mapping(a1, v18, *(unsigned __int16 *)(a1 + 12490), 1);
            }
            else
            {
              v20 = v17;
              _dp_ipa_handle_buf_smmu_mapping(a1, v18, *(unsigned __int16 *)(a1 + 12490), 0);
              if ( (v20[30] & 0x20) != 0 )
                v20[30] &= ~0x20u;
            }
          }
          else if ( (a2 & 1) != 0 )
          {
            if ( a1 )
              ++*(_DWORD *)(a1 + 14068);
          }
          else if ( a1 )
          {
            ++*(_DWORD *)(a1 + 14072);
          }
        }
        ++v15;
      }
      while ( v13 != v15 );
    }
  }
  else
  {
    raw_spin_lock_bh(a1 + 18520);
    *(_QWORD *)(a1 + 18528) |= 1uLL;
    v13 = *(_DWORD *)(a1 + 12416);
    if ( v13 )
      goto LABEL_11;
  }
  v21 = *(_QWORD *)(a1 + 18528);
  if ( (v21 & 1) != 0 )
  {
    *(_QWORD *)(a1 + 18528) = v21 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(a1 + 18520);
  }
  else
  {
    raw_spin_unlock(a1 + 18520);
  }
  v22 = *(_QWORD *)(a1 + 12480);
  if ( (v22 & 1) != 0 )
  {
    *(_QWORD *)(a1 + 12480) = v22 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(a1 + 12472);
  }
  else
  {
    raw_spin_unlock(a1 + 12472);
  }
  return dp_rx_set_reo_ctx_mapping_lock_required_0(a1, 0);
}
