__int64 __fastcall wlan_ipa_uc_rt_debug_host_fill(__int64 result)
{
  __int64 v1; // x20
  _QWORD *v2; // x21
  __int64 system_time; // x0
  __int64 v4; // x8
  __int64 v5; // x9
  __int64 v6; // x10
  __int64 v7; // x8
  __int64 v8; // x9
  __int64 v9; // x8
  __int64 v10; // x9

  if ( result )
  {
    v1 = result;
    qdf_mutex_acquire(result + 7160);
    v2 = (_QWORD *)(v1 + ((unsigned __int64)(*(_DWORD *)(v1 + 6256) % 0x1Eu) << 6));
    system_time = qdf_mc_timer_get_system_time();
    v4 = *(_QWORD *)(v1 + 3664);
    v5 = *(_QWORD *)(v1 + 4152);
    v6 = *(_QWORD *)(v1 + 4144);
    v2[542] = system_time;
    v2[543] = v4;
    v7 = *(_QWORD *)(v1 + 4128);
    v2[544] = v5;
    v8 = *(_QWORD *)(v1 + 3680);
    v2[545] = v6;
    LODWORD(v6) = *(_DWORD *)(v1 + 6256);
    v2[548] = v7;
    v9 = *(_QWORD *)(v1 + 4136);
    v2[547] = v8;
    v10 = *(_QWORD *)(v1 + 4160);
    v2[546] = v9;
    v2[549] = v10;
    *(_DWORD *)(v1 + 6256) = v6 + 1;
    qdf_mutex_release(v1 + 7160);
    return qdf_mc_timer_start(v1 + 6992, 0x2710u);
  }
  return result;
}
