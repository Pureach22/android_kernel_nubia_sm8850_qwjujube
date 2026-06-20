__int64 __fastcall hboost_notifier(__int64 a1, __int64 a2, int *a3)
{
  int v4; // w19

  if ( a2 )
    return 0;
  v4 = *a3;
  if ( (unsigned int)*a3 < 0x2711 )
  {
    *(_BYTE *)(a1 + 113) = (unsigned __int16)v4 / 0x32u;
    return 0;
  }
  else
  {
    if ( (unsigned int)__ratelimit(&hboost_notifier__rs, "hboost_notifier") )
      dev_err(
        *(_QWORD *)(a1 - 72),
        "%s: voted Vmax (%u mv) is higher than maximum (%u mv)\n",
        "hboost_notifier",
        v4,
        10000);
    return 4294967274LL;
  }
}
