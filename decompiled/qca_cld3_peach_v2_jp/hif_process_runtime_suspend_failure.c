__int64 hif_process_runtime_suspend_failure()
{
  __int64 v0; // x30
  __int64 v1; // x19
  __int64 v2; // x21
  unsigned __int64 StatusReg; // x8
  __int64 v4; // x8
  unsigned __int64 v5; // x21
  unsigned __int64 v6; // x23
  unsigned __int64 v7; // x9
  __int64 v8; // x11
  __int64 v9; // x9
  __int64 v10; // x0
  __int64 v11; // x24
  void (__fastcall *v12)(_QWORD); // x8
  __int64 v13; // x9
  __int64 v14; // x0
  unsigned __int64 v15; // x8
  unsigned __int64 v16; // x8
  __int64 v17; // x21
  __int64 result; // x0
  unsigned __int64 v19; // x9
  __int64 v20; // x8
  __int64 v21; // x9

  v1 = v0;
  v2 = gp_hif_rtpm_ctx;
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(v2 + 16);
  }
  else
  {
    raw_spin_lock_bh(v2 + 16);
    *(_QWORD *)(v2 + 24) |= 1uLL;
  }
  v4 = gp_hif_rtpm_ctx;
  *(_DWORD *)(gp_hif_rtpm_ctx + 188) = 1;
  if ( *(_DWORD *)(v4 + 48) )
  {
    v5 = 0;
    v6 = _ReadStatusReg(SP_EL0);
    do
    {
      v7 = v4 + 8 * (v5 >> 6);
      v8 = *(_QWORD *)(v7 + 192);
      *(_QWORD *)(v7 + 192) = v8 & ~(1LL << v5);
      if ( (v8 & (1LL << v5)) != 0 )
      {
        v9 = *(_QWORD *)(v4 + 24);
        if ( (v9 & 1) != 0 )
        {
          *(_QWORD *)(v4 + 24) = v9 & 0xFFFFFFFFFFFFFFFELL;
          v10 = raw_spin_unlock_bh(v4 + 16);
          if ( v5 >= 0xC )
          {
LABEL_22:
            __break(0x5512u);
            break;
          }
        }
        else
        {
          v10 = raw_spin_unlock(v4 + 16);
          if ( v5 >= 0xC )
            goto LABEL_22;
        }
        v11 = gp_hif_rtpm_ctx;
        v12 = **(void (__fastcall ***)(_QWORD))(gp_hif_rtpm_ctx + 8 * v5 + 56);
        if ( v12 )
        {
          if ( *((_DWORD *)v12 - 1) != -440107680 )
            __break(0x8228u);
          v12(v10);
          v11 = gp_hif_rtpm_ctx;
        }
        if ( (_ReadStatusReg(DAIF) & 0x80) != 0
          || (*(_DWORD *)(v6 + 16) & 0xF0000) != 0
          || (*(_DWORD *)(v6 + 16) & 0xFF00) != 0 )
        {
          raw_spin_lock(v11 + 16);
        }
        else
        {
          raw_spin_lock_bh(v11 + 16);
          *(_QWORD *)(v11 + 24) |= 1uLL;
        }
        v4 = gp_hif_rtpm_ctx;
      }
      ++v5;
    }
    while ( v5 < *(unsigned int *)(v4 + 48) );
  }
  v13 = *(_QWORD *)(v4 + 24);
  if ( (v13 & 1) != 0 )
  {
    *(_QWORD *)(v4 + 24) = v13 & 0xFFFFFFFFFFFFFFFELL;
    v14 = raw_spin_unlock_bh(v4 + 16);
  }
  else
  {
    v14 = raw_spin_unlock(v4 + 16);
  }
  ++*(_DWORD *)(gp_hif_rtpm_ctx + 216);
  __isb(0xFu);
  v15 = _ReadStatusReg(CNTVCT_EL0);
  *(_QWORD *)(gp_hif_rtpm_ctx + 240) = v15;
  __isb(0xFu);
  v16 = _ReadStatusReg(CNTVCT_EL0);
  v17 = *(_QWORD *)(gp_hif_rtpm_ctx + 8);
  *(_QWORD *)(gp_hif_rtpm_ctx + 248) = v16;
  result = ktime_get_mono_fast_ns(v14);
  *(_QWORD *)(v17 + 520) = result;
  __isb(0xFu);
  v19 = _ReadStatusReg(CNTVCT_EL0);
  v20 = gp_hif_rtpm_ctx;
  *(_QWORD *)(gp_hif_rtpm_ctx + 248) = v19;
  *(_DWORD *)(v20 + 256) = 0;
  v21 = *(_QWORD *)(v20 + 56);
  *(_QWORD *)(v20 + 264) = v1;
  if ( v21 )
  {
    ++*(_DWORD *)(v21 + 20);
    *(_QWORD *)(*(_QWORD *)(v20 + 56) + 40LL) = *(_QWORD *)(v20 + 248);
  }
  return result;
}
