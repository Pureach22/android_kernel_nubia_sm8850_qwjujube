__int64 __fastcall msm_dss_iounmap(__int64 a1)
{
  __int64 v1; // x30
  __int64 result; // x0

  if ( !a1 )
    return printk(&unk_22ECB8, v1);
  result = *(_QWORD *)(a1 + 8);
  if ( result )
  {
    result = iounmap();
    *(_QWORD *)(a1 + 8) = 0;
  }
  *(_DWORD *)a1 = 0;
  return result;
}
