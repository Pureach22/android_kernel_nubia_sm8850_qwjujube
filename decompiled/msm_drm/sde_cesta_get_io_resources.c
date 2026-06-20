__int64 __fastcall sde_cesta_get_io_resources(__int64 a1, __int64 a2)
{
  __int64 result; // x0
  unsigned int v3; // w19

  result = msm_dss_get_io_mem(*(_QWORD *)(a2 + 8) - 16LL, (__int64 *)(a1 + 16));
  if ( (_DWORD)result )
  {
    v3 = result;
    printk(&unk_244102, "sde_cesta_get_io_resources");
    return v3;
  }
  return result;
}
