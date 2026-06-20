__int64 __fastcall sde_encoder_early_wakeup_work_handler(__int64 result)
{
  __int64 v1; // x20
  __int64 v2; // x8
  __int64 v3; // x8
  __int64 v4; // x19
  __int64 v5; // x21
  __int64 v6; // x0
  __int64 v7; // x8
  __int64 (__fastcall *v8)(_QWORD); // x8
  int v9; // w4

  v1 = result - 1024;
  v2 = *(_QWORD *)(result - 1024);
  if ( v2 )
  {
    v3 = *(_QWORD *)(v2 + 56);
    if ( v3 )
    {
      v4 = *(_QWORD *)(v3 + 8);
      if ( v4 )
      {
        v5 = result;
        v6 = *(_QWORD *)(v4 + 6384);
        if ( !v6 )
          goto LABEL_10;
        mutex_lock(v6);
        v7 = *(_QWORD *)(v4 + 6384);
        if ( !v7 )
          goto LABEL_10;
        v8 = *(__int64 (__fastcall **)(_QWORD))(v7 + 88);
        if ( !v8 )
          goto LABEL_10;
        if ( *((_DWORD *)v8 - 1) != 1370937740 )
          __break(0x8228u);
        if ( (v8(v4) & 1) == 0 )
        {
          result = *(_QWORD *)(v4 + 6384);
          if ( result )
            result = mutex_unlock(result);
          if ( (_drm_debug & 4) != 0 )
          {
            if ( v1 )
              v9 = *(_DWORD *)(v5 - 1000);
            else
              v9 = -1;
            return _drm_dev_dbg(0, 0, 0, "skip early wakeup for ENC-%d, HW is owned by other VM\n", v9);
          }
        }
        else
        {
LABEL_10:
          _ReadStatusReg(SP_EL0);
          sde_encoder_resource_control(v1, 7);
          result = *(_QWORD *)(v4 + 6384);
          if ( result )
            return mutex_unlock(result);
        }
      }
    }
  }
  return result;
}
