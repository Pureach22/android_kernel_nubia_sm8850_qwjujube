__int64 __fastcall dcc_v2_thaw(__int64 a1)
{
  __int64 v1; // x19
  __int64 result; // x0

  v1 = *(_QWORD *)(a1 + 152);
  if ( v1 && *(_QWORD *)(v1 + 360) && *(_QWORD *)(v1 + 368) )
  {
    kfree(*(_QWORD *)(v1 + 368));
    kfree(*(_QWORD *)(v1 + 360));
    result = 0;
    *(_QWORD *)(v1 + 360) = 0;
    *(_QWORD *)(v1 + 368) = 0;
  }
  else
  {
    dev_err(a1, "Err: %s Invalid argument\n", "dcc_v2_thaw");
    return 4294967274LL;
  }
  return result;
}
