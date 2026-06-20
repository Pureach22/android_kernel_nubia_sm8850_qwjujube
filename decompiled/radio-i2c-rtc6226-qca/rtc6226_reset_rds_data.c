__int64 __fastcall rtc6226_reset_rds_data(__int64 a1)
{
  _QWORD *v2; // x20
  size_t v3; // x2
  void *v4; // x0

  v2 = (_QWORD *)(a1 + 2820);
  mutex_lock(a1 + 1872);
  v3 = *(unsigned int *)(a1 + 3120);
  v4 = *(void **)(a1 + 1920);
  *(_QWORD *)(a1 + 2562) = 0;
  *(_QWORD *)(a1 + 2570) = 0;
  *(_QWORD *)(a1 + 2578) = 0;
  *(_QWORD *)(a1 + 2586) = 0;
  *(_QWORD *)(a1 + 2594) = 0;
  *(_QWORD *)(a1 + 2602) = 0;
  *(_QWORD *)(a1 + 2610) = 0;
  *(_QWORD *)(a1 + 2618) = 0;
  *(_QWORD *)(a1 + 2626) = 0;
  *(_QWORD *)(a1 + 2634) = 0;
  *(_QWORD *)(a1 + 2642) = 0;
  *(_QWORD *)(a1 + 2650) = 0;
  *(_QWORD *)(a1 + 2658) = 0;
  *(_QWORD *)(a1 + 2666) = 0;
  *(_QWORD *)(a1 + 2674) = 0;
  *(_QWORD *)(a1 + 2682) = 0;
  *(_QWORD *)(a1 + 2738) = 0;
  *(_QWORD *)(a1 + 2746) = 0;
  *(_QWORD *)(a1 + 2722) = 0;
  *(_QWORD *)(a1 + 2730) = 0;
  *(_QWORD *)(a1 + 2706) = 0;
  *(_QWORD *)(a1 + 2714) = 0;
  *(_QWORD *)(a1 + 2690) = 0;
  *(_QWORD *)(a1 + 2698) = 0;
  *v2 = 0;
  v2[1] = 0;
  v2[2] = 0;
  v2[3] = 0;
  *(_QWORD *)(a1 + 2754) = 0;
  *(_QWORD *)(a1 + 2762) = 0;
  *(_QWORD *)(a1 + 2770) = 0;
  *(_QWORD *)(a1 + 2778) = 0;
  *(_QWORD *)(a1 + 2786) = 0;
  *(_QWORD *)(a1 + 2794) = 0;
  *(_QWORD *)(a1 + 2802) = 0;
  *(_QWORD *)(a1 + 2810) = 0;
  *(_QWORD *)(a1 + 3124) = 0;
  *(_WORD *)(a1 + 2550) = 0;
  memset(v4, 0, v3);
  mutex_unlock(a1 + 1872);
  return 0;
}
