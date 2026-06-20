__int64 __fastcall _hif_pm_runtime_allow_suspend(__int64 result)
{
  __int64 v1; // x30
  __int64 v2; // x22
  int v3; // w9
  _QWORD *v4; // x19
  __int64 v5; // x20
  unsigned __int64 StatusReg; // x9
  __int64 v7; // x8
  __int64 v8; // x9
  _QWORD *v9; // x9
  __int64 v10; // x10
  _QWORD *v11; // x8
  __int64 v12; // x9
  int v13; // w10

  if ( *(_DWORD *)(gp_hif_rtpm_ctx + 184) && *(_BYTE *)(result + 16) == 1 )
  {
    v2 = *(_QWORD *)(gp_hif_rtpm_ctx + 8);
    v3 = *(_DWORD *)(v2 + 480);
    if ( v3 )
    {
      if ( v3 == 2 && (*(_BYTE *)gp_hif_rtpm_ctx & 1) == 0 )
      {
        return qdf_trace_msg(61, 2, "%s: Unexpected PUT when runtime PM is disabled", "__hif_pm_runtime_allow_suspend");
      }
      else
      {
        v4 = (_QWORD *)result;
        v5 = v1;
        *(_QWORD *)(v2 + 520) = ktime_get_mono_fast_ns(result);
        __isb(0xFu);
        StatusReg = _ReadStatusReg(CNTVCT_EL0);
        v7 = gp_hif_rtpm_ctx;
        *(_QWORD *)(gp_hif_rtpm_ctx + 248) = StatusReg;
        *(_DWORD *)(v7 + 256) = 0;
        v8 = *(_QWORD *)(v7 + 56);
        *(_QWORD *)(v7 + 264) = v5;
        if ( v8 )
        {
          ++*(_DWORD *)(v8 + 20);
          *(_QWORD *)(*(_QWORD *)(v7 + 56) + 40LL) = *(_QWORD *)(v7 + 248);
        }
        result = _pm_runtime_suspend(*(_QWORD *)(v7 + 8), 13);
        v9 = (_QWORD *)v4[1];
        if ( (_QWORD *)*v9 == v4 && (v10 = *v4, v11 = v4, *(_QWORD **)(*v4 + 8LL) == v4) )
        {
          *(_QWORD *)(v10 + 8) = v9;
          *v9 = v10;
        }
        else
        {
          result = _list_del_entry_valid_or_report(v4);
          v11 = v4;
        }
        *((_BYTE *)v11 + 16) = 0;
        *v11 = 0xDEAD000000000100LL;
        v11[1] = 0xDEAD000000000122LL;
        v12 = gp_hif_rtpm_ctx;
        v13 = *(_DWORD *)(gp_hif_rtpm_ctx + 292) + 1;
        --*(_DWORD *)(gp_hif_rtpm_ctx + 184);
        *(_DWORD *)(v12 + 292) = v13;
      }
    }
    else
    {
      return qdf_trace_msg(
               61,
               5,
               "%s: Put without a Get operation, %s",
               "__hif_pm_runtime_allow_suspend",
               *(const char **)(result + 24));
    }
  }
  return result;
}
