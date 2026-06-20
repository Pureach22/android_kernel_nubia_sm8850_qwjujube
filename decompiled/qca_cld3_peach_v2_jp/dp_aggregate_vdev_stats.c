__int64 __fastcall dp_aggregate_vdev_stats(__int64 result, __int64 a2, unsigned int a3)
{
  _QWORD *v3; // x19
  __int64 v6; // x8
  __int64 v7; // x21
  unsigned __int64 StatusReg; // x8
  __int64 v9; // x23
  __int64 v10; // x22
  unsigned int v11; // w8
  unsigned int v18; // w10
  double updated; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7
  unsigned int v29; // w9
  __int64 v30; // x8

  if ( result )
  {
    v3 = (_QWORD *)result;
    if ( *(_QWORD *)(result + 24) )
    {
      dp_update_vdev_ingress_stats(result);
      dp_copy_vdev_stats_to_tgt_buf(a2, v3 + 50, a3);
      v6 = v3[3];
      if ( !v6 )
        return dp_update_vdev_rate_stats(a2, v3 + 50);
      v7 = *(_QWORD *)(v6 + 8);
      if ( !v7 )
        return dp_update_vdev_rate_stats(a2, v3 + 50);
      if ( (_ReadStatusReg(DAIF) & 0x80) != 0
        || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
        || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
      {
        raw_spin_lock(v3 + 17);
        v9 = v3[15];
        while ( v9 )
        {
LABEL_9:
          v10 = v9;
          v9 = *(_QWORD *)(v9 + 56);
          v11 = *(_DWORD *)(v10 + 40);
          while ( v11 )
          {
            _X12 = (unsigned int *)(v10 + 40);
            __asm { PRFM            #0x11, [X12] }
            while ( 1 )
            {
              v18 = __ldxr(_X12);
              if ( v18 != v11 )
                break;
              if ( !__stlxr(v11 + 1, _X12) )
              {
                __dmb(0xBu);
                break;
              }
            }
            _ZF = v18 == v11;
            v11 = v18;
            if ( _ZF )
            {
              _X8 = (unsigned int *)(v10 + 288);
              __asm { PRFM            #0x11, [X8] }
              do
                v29 = __ldxr(_X8);
              while ( __stxr(v29 + 1, _X8) );
              updated = dp_update_vdev_stats(v7, v10, a2);
              dp_peer_unref_delete(v10, 8u, updated, v20, v21, v22, v23, v24, v25, v26);
              break;
            }
          }
        }
      }
      else
      {
        raw_spin_lock_bh(v3 + 17);
        v3[18] |= 1uLL;
        v9 = v3[15];
        if ( v9 )
          goto LABEL_9;
      }
      v30 = v3[18];
      if ( (v30 & 1) != 0 )
      {
        v3[18] = v30 & 0xFFFFFFFFFFFFFFFELL;
        raw_spin_unlock_bh(v3 + 17);
      }
      else
      {
        raw_spin_unlock(v3 + 17);
      }
      return dp_update_vdev_rate_stats(a2, v3 + 50);
    }
  }
  return result;
}
