__int64 __fastcall sde_kms_commit(
        __int64 result,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        int a8)
{
  __int64 v9; // x8
  __int64 v10; // x20
  unsigned __int64 StatusReg; // x19
  __int64 v12; // x8
  __int64 v13; // x25
  __int64 v14; // x26
  __int64 v15; // x9
  __int64 v16; // x23
  __int64 v17; // x24
  __int64 v18; // x8
  unsigned int v19; // w8
  __int64 (__fastcall *v20)(__int64, __int64); // x8
  __int64 v21; // x23
  __int64 (__fastcall *v22)(__int64, __int64, unsigned __int64, const char *, _QWORD); // x8
  __int64 v23; // x0
  __int64 v24; // t1
  __int64 v25; // x8
  char v26; // [xsp+0h] [xbp+0h]

  if ( result && a2 )
  {
    v9 = *(_QWORD *)(result + 136);
    v10 = result;
    if ( !v9 || (*(_WORD *)(*(_QWORD *)(v9 + 8) + 488LL) & 7) != 0 )
    {
      return printk(&unk_24FBDF, "sde_kms_commit");
    }
    else
    {
      StatusReg = _ReadStatusReg(SP_EL0);
      while ( 1 )
      {
        v12 = *(_QWORD *)(a2 + 8);
        if ( *(int *)(v12 + 860) >= 1 )
        {
          v13 = 0;
          v14 = 0;
          do
          {
            v15 = *(_QWORD *)(a2 + 32);
            v16 = *(_QWORD *)(v15 + v13);
            if ( v16 && *(_BYTE *)(*(_QWORD *)(v16 + 2008) + 9LL) == 1 )
            {
              v17 = *(_QWORD *)(v15 + v13 + 16);
              sde_evtlog_log(
                sde_dbg_base_evtlog,
                "sde_kms_commit",
                1453,
                -1,
                *(_DWORD *)(v16 + 112),
                a2,
                -1059143953,
                a8,
                v26);
              result = sde_crtc_commit_kickoff(v16, v17);
              v12 = *(_QWORD *)(a2 + 8);
            }
            ++v14;
            v13 += 56;
          }
          while ( v14 < *(int *)(v12 + 860) );
        }
        v18 = *(_QWORD *)(*(_QWORD *)(v10 + 136) + 56LL);
        if ( !v18 )
          break;
        v19 = *(_DWORD *)(v18 + 5912);
        if ( v19 < 3 )
          goto LABEL_14;
        __break(0x5512u);
        if ( ((*(_QWORD *)((char *)&_cpu_online_mask
                         + (((unsigned __int64)*(unsigned int *)(StatusReg + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(StatusReg + 40))
            & 1) != 0 )
        {
          ++*(_DWORD *)(StatusReg + 16);
          v21 = qword_29E3D0;
          if ( qword_29E3D0 )
          {
            do
            {
              v22 = *(__int64 (__fastcall **)(__int64, __int64, unsigned __int64, const char *, _QWORD))v21;
              v23 = *(_QWORD *)(v21 + 8);
              if ( *(_DWORD *)(*(_QWORD *)v21 - 4LL) != -641035679 )
                __break(0x8228u);
              result = v22(v23, 66, StatusReg, "sde_kms_commit", 0);
              v24 = *(_QWORD *)(v21 + 24);
              v21 += 24;
            }
            while ( v24 );
          }
          v25 = *(_QWORD *)(StatusReg + 16) - 1LL;
          *(_DWORD *)(StatusReg + 16) = v25;
          if ( !v25 || !*(_QWORD *)(StatusReg + 16) )
            result = preempt_schedule_notrace(result);
        }
      }
      result = printk(&unk_25E374, "sde_kms_get_disp_op");
      v19 = 0;
LABEL_14:
      v20 = *(__int64 (__fastcall **)(__int64, __int64))(v10 + 8LL * v19 + 6760);
      if ( v20 )
      {
        if ( *((_DWORD *)v20 - 1) != -307910306 )
          __break(0x8228u);
        result = v20(v10, a2);
        if ( (_DWORD)result )
          return printk(&unk_22B063, "sde_kms_commit");
      }
    }
  }
  return result;
}
