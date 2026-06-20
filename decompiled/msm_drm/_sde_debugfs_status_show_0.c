__int64 __fastcall sde_debugfs_status_show_0(__int64 a1)
{
  __int64 v1; // x20
  _QWORD *v3; // x28
  _QWORD *v4; // x26
  int v5; // w27
  int v6; // w4
  __int64 result; // x0
  __int64 (__fastcall *v8)(_QWORD); // x8
  int v9; // w0
  _QWORD *i; // x23
  void (__fastcall *v11)(__int64, __int64, __int64 *); // x8
  __int64 v12; // x1
  __int64 v13; // [xsp+8h] [xbp-18h] BYREF
  __int64 v14; // [xsp+10h] [xbp-10h]
  __int64 v15; // [xsp+18h] [xbp-8h]

  v15 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v13 = 0;
  v14 = 0;
  if ( a1 && (v1 = *(_QWORD *)(a1 + 128)) != 0 )
  {
    mutex_lock(v1 + 800);
    v3 = *(_QWORD **)(v1 + 784);
    v4 = (_QWORD *)(v1 + 784);
    if ( v3 == (_QWORD *)(v1 + 784) )
    {
      v5 = 0;
    }
    else
    {
      LOBYTE(v5) = 0;
      do
      {
        v6 = *((unsigned __int8 *)v3 - 48);
        v5 = v6 | v5 & 1;
        seq_printf(a1, "client%d:%s en:%d\n", *((_DWORD *)v3 - 26), (const char *)v3 - 80, v6);
        seq_printf(
          a1,
          "\t pwr_override:%d vote_state:%d aoss_cp_level:%d\n",
          *((unsigned __int8 *)v3 - 47),
          *((_DWORD *)v3 - 11),
          *((_DWORD *)v3 - 2));
        seq_printf(a1, "\t HW-Client - core_clk[ab,ib]:%llu,%llu ", *(v3 - 3), *(v3 - 2));
        seq_printf(a1, "bw[ab,ib]:%llu,%llu ", *(v3 - 5), *(v3 - 4));
        seq_write(a1, "\n\n", 2);
        v3 = (_QWORD *)*v3;
      }
      while ( v3 != v4 );
    }
    seq_printf(a1, "SW-Client-0 - core_clk[ab,ib]:%llu,%llu ", *(_QWORD *)(v1 + 1096), *(_QWORD *)(v1 + 1104));
    seq_printf(a1, "bw[ab,ib]:%llu,%llu ", *(_QWORD *)(v1 + 1080), *(_QWORD *)(v1 + 1088));
    seq_printf(a1, "aoss_cp_level:%d\n", *(_DWORD *)(v1 + 1112));
    seq_write(a1, "\n\n", 2);
    if ( v5 )
    {
      if ( *(_QWORD *)(v1 + 872) )
      {
        v8 = *(__int64 (__fastcall **)(_QWORD))(v1 + 880);
        if ( v8 )
        {
          if ( *((_DWORD *)v8 - 1) != 722369561 )
            __break(0x8228u);
          v9 = v8(v1);
          seq_printf(a1, "PWR_event:%d\n", v9);
          for ( i = *(_QWORD **)(v1 + 784); i != v4; i = (_QWORD *)*i )
          {
            v11 = *(void (__fastcall **)(__int64, __int64, __int64 *))(v1 + 872);
            v12 = *((unsigned int *)i - 26);
            if ( *((_DWORD *)v11 - 1) != -1476338332 )
              __break(0x8228u);
            v11(v1, v12, &v13);
            seq_printf(a1, "SCC[%d] status - ", *((_DWORD *)i - 26));
            seq_printf(
              a1,
              "frame_region:%d scc_hshake:%d fsm_st:%d flush_miss_cnt:%d\n",
              v13,
              HIDWORD(v13),
              v14,
              HIDWORD(v14));
          }
        }
      }
    }
    seq_putc(a1, 10);
    mutex_unlock(v1 + 800);
    result = 0;
  }
  else
  {
    result = 4294967274LL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
