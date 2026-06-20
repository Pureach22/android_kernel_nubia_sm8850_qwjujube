__int64 hif_process_runtime_resume_linkup()
{
  __int64 v0; // x20
  unsigned __int64 StatusReg; // x8
  __int64 v2; // x8
  unsigned __int64 v3; // x20
  unsigned __int64 v4; // x22
  unsigned __int64 v5; // x9
  __int64 v6; // x11
  __int64 v7; // x9
  __int64 v8; // x0
  __int64 v9; // x23
  void (__fastcall *v10)(_QWORD); // x8
  __int64 v11; // x9

  v0 = gp_hif_rtpm_ctx;
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(v0 + 16);
  }
  else
  {
    raw_spin_lock_bh(v0 + 16);
    *(_QWORD *)(v0 + 24) |= 1uLL;
  }
  v2 = gp_hif_rtpm_ctx;
  *(_DWORD *)(gp_hif_rtpm_ctx + 188) = 2;
  if ( *(_DWORD *)(v2 + 48) )
  {
    v3 = 0;
    v4 = _ReadStatusReg(SP_EL0);
    do
    {
      v5 = v2 + 8 * (v3 >> 6);
      v6 = *(_QWORD *)(v5 + 192);
      *(_QWORD *)(v5 + 192) = v6 & ~(1LL << v3);
      if ( (v6 & (1LL << v3)) != 0 )
      {
        v7 = *(_QWORD *)(v2 + 24);
        if ( (v7 & 1) != 0 )
        {
          *(_QWORD *)(v2 + 24) = v7 & 0xFFFFFFFFFFFFFFFELL;
          v8 = raw_spin_unlock_bh(v2 + 16);
          if ( v3 >= 0xC )
          {
LABEL_22:
            __break(0x5512u);
            break;
          }
        }
        else
        {
          v8 = raw_spin_unlock(v2 + 16);
          if ( v3 >= 0xC )
            goto LABEL_22;
        }
        v9 = gp_hif_rtpm_ctx;
        v10 = **(void (__fastcall ***)(_QWORD))(gp_hif_rtpm_ctx + 8 * v3 + 56);
        if ( v10 )
        {
          if ( *((_DWORD *)v10 - 1) != -440107680 )
            __break(0x8228u);
          v10(v8);
          v9 = gp_hif_rtpm_ctx;
        }
        if ( (_ReadStatusReg(DAIF) & 0x80) != 0
          || (*(_DWORD *)(v4 + 16) & 0xF0000) != 0
          || (*(_DWORD *)(v4 + 16) & 0xFF00) != 0 )
        {
          raw_spin_lock(v9 + 16);
        }
        else
        {
          raw_spin_lock_bh(v9 + 16);
          *(_QWORD *)(v9 + 24) |= 1uLL;
        }
        v2 = gp_hif_rtpm_ctx;
      }
      ++v3;
    }
    while ( v3 < *(unsigned int *)(v2 + 48) );
  }
  v11 = *(_QWORD *)(v2 + 24);
  if ( (v11 & 1) == 0 )
    return raw_spin_unlock(v2 + 16);
  *(_QWORD *)(v2 + 24) = v11 & 0xFFFFFFFFFFFFFFFELL;
  return raw_spin_unlock_bh(v2 + 16);
}
