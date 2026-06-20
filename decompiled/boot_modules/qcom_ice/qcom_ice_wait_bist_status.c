__int64 __fastcall qcom_ice_wait_bist_status(_QWORD *a1)
{
  __int64 v2; // x20
  __int64 v3; // x20
  unsigned int v4; // w20
  int v5; // w21

  v2 = ktime_get();
  if ( !((unsigned int)readl(a1[1] + 112LL) >> 28) )
    goto LABEL_7;
  v3 = v2 + 5000000;
  while ( ktime_get() <= v3 )
  {
    usleep_range_state(13, 50, 2);
    __yield();
    if ( !((unsigned int)readl(a1[1] + 112LL) >> 28) )
      goto LABEL_7;
  }
  if ( (unsigned int)readl(a1[1] + 112LL) >> 28 )
  {
    dev_err(*a1, "Timed out waiting for ICE self-test to complete\n");
    v4 = -110;
  }
  else
  {
LABEL_7:
    v4 = 0;
  }
  if ( *((_BYTE *)a1 + 33) == 1 )
  {
    if ( *((_BYTE *)a1 + 32) == 1 )
      v5 = 17;
    else
      v5 = 647;
    if ( (unsigned int)readl(a1[1] + 36868LL) != v5 )
    {
      dev_warn(*a1, "HWKM BIST error\n");
      *((_BYTE *)a1 + 33) = 0;
    }
  }
  return v4;
}
