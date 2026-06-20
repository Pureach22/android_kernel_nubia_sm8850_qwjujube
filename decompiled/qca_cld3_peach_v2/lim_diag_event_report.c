__int64 __fastcall lim_diag_event_report(__int64 a1, __int16 a2, int *a3, __int16 a4, __int16 a5)
{
  int *v10; // x8
  int *v11; // x9
  int v12; // w8
  int v13; // w9
  __int64 result; // x0
  __int64 v15; // [xsp+0h] [xbp-20h] BYREF
  __int64 v16; // [xsp+8h] [xbp-18h]
  int v17; // [xsp+10h] [xbp-10h] BYREF
  __int16 v18; // [xsp+14h] [xbp-Ch]
  __int64 v19; // [xsp+18h] [xbp-8h]

  v19 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v18 = 0;
  v17 = 0;
  v15 = 0;
  v16 = 0;
  qdf_mem_set(&v15, 0x10u, 0);
  if ( a3 )
  {
    qdf_mem_copy(&v15, a3 + 6, 6u);
    v10 = a3 + 20;
    v11 = a3 + 18;
  }
  else
  {
    qdf_mem_copy(&v15, &v17, 6u);
    v10 = (int *)(a1 + 4056);
    v11 = (int *)(a1 + 4020);
  }
  v12 = *v10;
  v13 = *v11;
  HIWORD(v15) = a2;
  LOWORD(v16) = v12;
  WORD1(v16) = v13;
  WORD2(v16) = a4;
  HIWORD(v16) = a5;
  result = host_diag_event_report_payload(1658, 16, &v15);
  _ReadStatusReg(SP_EL0);
  return result;
}
