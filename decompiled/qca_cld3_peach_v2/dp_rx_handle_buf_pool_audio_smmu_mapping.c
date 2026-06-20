__int64 __fastcall dp_rx_handle_buf_pool_audio_smmu_mapping(__int64 a1, unsigned __int8 a2, char a3)
{
  __int64 v5; // x21
  unsigned __int64 StatusReg; // x8
  int v7; // w24
  unsigned int v8; // w26
  unsigned int v9; // w25
  int v10; // w27
  _BYTE *v11; // x0
  __int64 v12; // x28
  int v13; // w8
  __int64 v14; // x22
  __int64 v15; // x2
  __int64 v16; // x8
  __int64 v17; // x0
  __int64 v18; // x8
  __int64 v19; // x23
  __int64 v20; // x0
  __int64 v21; // x1
  __int64 v22; // x8

  *(_DWORD *)(a1 + 20264) = a3 & 1;
  if ( (*(_BYTE *)(*(_QWORD *)(a1 + 40) + 831LL) & 1) != 0 )
    return 0;
  if ( a2 >= 5u )
  {
    __break(0x5512u);
    JUMPOUT(0x53CAAC);
  }
  v5 = a1 + 120LL * a2 + 12416;
  ((void (__fastcall *)(__int64, __int64))dp_rx_set_reo_ctx_mapping_lock_required)(a1, 1);
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(a1 + 18520);
    v7 = *(_DWORD *)v5;
    if ( *(_DWORD *)v5 )
    {
LABEL_7:
      v8 = *(unsigned __int16 *)(v5 + 8);
      v9 = 0;
      if ( (a3 & 1) != 0 )
        v10 = 0x2000000;
      else
        v10 = 0;
      do
      {
        if ( !*(_QWORD *)(v5 + 24) )
          break;
        v11 = (_BYTE *)dp_rx_desc_find(v9 / v8, v9 % v8, v5);
        if ( (v11[30] & 3) == 1 )
        {
          v12 = *(_QWORD *)v11;
          v13 = *(_DWORD *)(*(_QWORD *)v11 + 48LL);
          if ( ((v13 & 0x2000000) == 0) == (a3 & 1) )
          {
            *(_DWORD *)(v12 + 48) = v13 & 0xFDFFFFFF | v10;
            v14 = *(unsigned __int16 *)(v5 + 74);
            if ( (a3 & 1) != 0 )
            {
              v15 = *(_QWORD *)(v12 + 40);
              *(_DWORD *)(v12 + 48) = v13 | 0x2000000;
              v16 = *(_QWORD *)(a1 + 24);
              v17 = *(_QWORD *)(v16 + 40);
              if ( *(_BYTE *)(v16 + 608) == 1 && (v18 = *(_QWORD *)(v16 + 616)) != 0 )
              {
                v19 = v17;
                v20 = iommu_iova_to_phys(v18, v15);
                v15 = *(_QWORD *)(v12 + 40);
                v21 = v20;
                v17 = v19;
              }
              else
              {
                v21 = v15;
              }
              pld_audio_smmu_map(v17, v21, v15, v14);
            }
            else
            {
              *(_DWORD *)(v12 + 48) = v13 & 0xFDFFFFFF;
              pld_audio_smmu_unmap(*(_QWORD *)(*(_QWORD *)(a1 + 24) + 40LL), *(_QWORD *)(v12 + 40), v14);
            }
          }
          else if ( (a3 & 1) != 0 )
          {
            if ( a1 )
              ++*(_DWORD *)(a1 + 14080);
          }
          else if ( a1 )
          {
            ++*(_DWORD *)(a1 + 14084);
          }
        }
        ++v9;
      }
      while ( v7 != v9 );
    }
  }
  else
  {
    raw_spin_lock_bh(a1 + 18520);
    *(_QWORD *)(a1 + 18528) |= 1uLL;
    v7 = *(_DWORD *)v5;
    if ( *(_DWORD *)v5 )
      goto LABEL_7;
  }
  v22 = *(_QWORD *)(a1 + 18528);
  if ( (v22 & 1) != 0 )
  {
    *(_QWORD *)(a1 + 18528) = v22 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(a1 + 18520);
  }
  else
  {
    raw_spin_unlock(a1 + 18520);
  }
  ((void (__fastcall *)(__int64, _QWORD))dp_rx_set_reo_ctx_mapping_lock_required)(a1, 0);
  return 0;
}
