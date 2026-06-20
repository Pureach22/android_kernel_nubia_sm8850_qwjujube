__int64 __fastcall msm_vidc_trigger_stability(__int64 a1, unsigned __int64 a2)
{
  __int64 *v4; // x21
  int v5; // w23
  unsigned __int64 v6; // x24
  int v7; // w20
  __int64 v8; // x1

  mutex_lock(a1 + 3856);
  v4 = *(__int64 **)(a1 + 3528);
  if ( v4 != (__int64 *)(a1 + 3528) )
  {
    v5 = (unsigned __int8)a2 >> 4;
    v6 = HIDWORD(a2);
    v7 = a2 & 0xF;
    do
    {
      v8 = system_wq;
      *((_DWORD *)v4 + 988) = v7;
      *((_DWORD *)v4 + 989) = v5;
      *((_DWORD *)v4 + 990) = v6;
      queue_work_on(32, v8, v4 + 490);
      v4 = (__int64 *)*v4;
    }
    while ( v4 != (__int64 *)(a1 + 3528) );
  }
  mutex_unlock(a1 + 3856);
  return 0;
}
