// positive sp value has been detected, the output may be wrong!
__int64 __fastcall sub_7B494(__int64 a1, __int64 a2, __int64 a3)
{
  _QWORD *v3; // x19
  unsigned int v4; // w20
  int v5; // w21
  int v6; // w22
  int v7; // w24
  char v8; // w27
  int v10; // w23
  int v11; // w24
  int v12; // w25
  int v13; // w26
  int v14; // w0
  unsigned int v15; // w21

  if ( !v7 )
    return ((__int64 (*)(void))a5xx_power_stats)();
  v10 = ((__int64 (__fastcall *)(__int64, __int64, __int64, _QWORD, __int64))timed_poll_check_rscc)(a1, a2, a3, v4, 1);
  v11 = ((__int64 (__fastcall *)(_QWORD *, __int64, __int64, _QWORD, __int64))timed_poll_check_rscc)(v3, 1846, 1, v4, 1);
  v12 = ((__int64 (__fastcall *)(_QWORD *, __int64, __int64, _QWORD, __int64))timed_poll_check_rscc)(v3, 2014, 1, v4, 1);
  v13 = ((__int64 (__fastcall *)(_QWORD *, __int64, __int64, _QWORD, __int64))timed_poll_check_rscc)(v3, 2182, 1, v4, 1);
  v14 = ((__int64 (__fastcall *)(_QWORD *, __int64, __int64, _QWORD, __int64))timed_poll_check_rscc)(v3, 2350, 1, v4, 1);
  if ( (v8 & 1) == 0 )
  {
    __break(0x5512u);
    JUMPOUT(0x88CA4);
  }
  v15 = v6 | v10 | v11 | v12 | v13 | v14 | v5;
  if ( v15 )
    dev_err(*v3, "RPMH votes timedout: %d\n", v15);
  return v15;
}
