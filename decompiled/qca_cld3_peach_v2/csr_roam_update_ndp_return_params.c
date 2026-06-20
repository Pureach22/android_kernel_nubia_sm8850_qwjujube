__int64 __fastcall csr_roam_update_ndp_return_params(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        __int64 a9,
        int a10,
        _DWORD *a11,
        int *a12,
        __int64 a13)
{
  __int64 v13; // x29
  __int64 v14; // x30
  int v15; // w8
  __int64 result; // x0
  char v17; // w8

  if ( a10 <= 1 )
  {
    if ( !a10 )
    {
      v17 = *(_BYTE *)(a13 + 41);
      *(_QWORD *)(a13 + 184) = 0;
      *(_BYTE *)(a13 + 192) = v17;
      goto LABEL_10;
    }
    if ( a10 == 1 )
    {
      *(_QWORD *)(a13 + 184) = 0x232900000001LL;
LABEL_10:
      v15 = 20;
      goto LABEL_11;
    }
    return qdf_trace_msg(
             0x34u,
             2u,
             "%s: Invalid CSR Roam result code: %d",
             a1,
             a2,
             a3,
             a4,
             a5,
             a6,
             a7,
             a8,
             "csr_roam_update_ndp_return_params",
             (unsigned int)a10,
             v13,
             v14);
  }
  if ( a10 != 2 )
  {
    if ( a10 == 3 )
    {
      *(_QWORD *)(a13 + 184) = 0x232A00000001LL;
      v15 = 21;
LABEL_11:
      *a11 = 43;
      *a12 = v15;
      return result;
    }
    return qdf_trace_msg(
             0x34u,
             2u,
             "%s: Invalid CSR Roam result code: %d",
             a1,
             a2,
             a3,
             a4,
             a5,
             a6,
             a7,
             a8,
             "csr_roam_update_ndp_return_params",
             (unsigned int)a10,
             v13,
             v14);
  }
  *(_QWORD *)(a13 + 184) = 0;
  *a11 = 43;
  *a12 = 21;
  return result;
}
