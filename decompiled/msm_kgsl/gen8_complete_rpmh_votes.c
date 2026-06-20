__int64 __fastcall gen8_complete_rpmh_votes(__int64 a1, int a2)
{
  int v4; // w21
  int v5; // w22
  int v6; // w21
  int v7; // w22
  int v8; // w21
  int v9; // w21
  int v10; // w22
  int v11; // w21
  int v12; // w21
  __int64 result; // x0
  __int64 v14; // x8
  unsigned int v15; // w19

  v4 = gen8_timed_poll_check_rscc(a1, 842, 1, a2, 1);
  v5 = gen8_timed_poll_check_rscc(a1, 1010, 1, a2, 1) | v4;
  v6 = gen8_timed_poll_check_rscc(a1, 1178, 1, a2, 1);
  v7 = gen8_timed_poll_check_rscc(a1, 1346, 1, a2, 1) | v6 | v5;
  v8 = gen8_timed_poll_check_rscc(a1, 1514, 1, a2, 1);
  v9 = gen8_timed_poll_check_rscc(a1, 1682, 1, a2, 1) | v8;
  v10 = gen8_timed_poll_check_rscc(a1, 1850, 1, a2, 1) | v9 | v7;
  v11 = gen8_timed_poll_check_rscc(a1, 2018, 1, a2, 1);
  v12 = gen8_timed_poll_check_rscc(a1, 2186, 1, a2, 1) | v11;
  result = (unsigned int)gen8_timed_poll_check_rscc(a1, 2354, 1, a2, 1) | v12 | v10;
  if ( (_DWORD)result )
  {
    v14 = *(_QWORD *)(a1 + 3368);
    v15 = result;
    dev_err(v14 + 16, "RPMH votes timedout: %d\n", result);
    return v15;
  }
  return result;
}
