__int64 __fastcall qsmmuv500_create(_QWORD *a1, __int64 a2)
{
  __int64 v2; // x19
  __int64 v4; // x0
  __int64 v5; // x20
  __int64 result; // x0

  v2 = *a1;
  v4 = devm_krealloc(*a1, a1, 400, 3520);
  if ( !v4 )
    return -12;
  *(_QWORD *)(v4 + 328) = v4 + 328;
  *(_QWORD *)(v4 + 336) = v4 + 328;
  *(_QWORD *)(v4 + 360) = 0xFFFFFFFE00000LL;
  *(_DWORD *)(v4 + 392) = 0;
  *(_QWORD *)(v4 + 368) = v4 + 368;
  *(_QWORD *)(v4 + 376) = v4 + 368;
  *(_QWORD *)(v4 + 384) = qsmmuv500_log_outstanding_transactions;
  *(_QWORD *)(v4 + 48) = a2;
  v5 = v4;
  LODWORD(result) = ((__int64 (*)(void))qsmmuv500_read_actlr_tbl)();
  if ( (_DWORD)result )
    return (int)result;
  LODWORD(result) = of_platform_populate(*(_QWORD *)(v2 + 744), 0, 0, v2);
  if ( (_DWORD)result )
    return (int)result;
  if ( (unsigned int)device_for_each_child(v2, v5, qsmmuv500_tbu_register) )
    return -517;
  return v5;
}
