__int64 __fastcall dp_srng_access_end(
        __int64 a1,
        __int64 a2,
        char *a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 v12; // x20
  char v13; // w11
  unsigned __int8 v14; // w2
  int v15; // w9
  int v16; // w8
  int v17; // w10
  bool v18; // zf
  __int64 v19; // x8
  int v20; // w11
  __int64 v21; // x8
  __int64 result; // x0
  __int64 v23; // [xsp+8h] [xbp-28h] BYREF
  __int64 v24; // [xsp+10h] [xbp-20h]
  __int64 v25; // [xsp+18h] [xbp-18h]
  __int64 v26; // [xsp+20h] [xbp-10h]
  __int64 v27; // [xsp+28h] [xbp-8h]

  v27 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v12 = *(_QWORD *)(a2 + 1128);
  if ( !a1 )
  {
    if ( a3 )
      goto LABEL_8;
LABEL_13:
    result = qdf_trace_msg(
               0x38u,
               2u,
               "%s: Error: Invalid hal_ring\n",
               a4,
               a5,
               a6,
               a7,
               a8,
               a9,
               a10,
               a11,
               "hal_srng_access_end");
    goto LABEL_11;
  }
  v13 = *a3;
  v14 = *(_BYTE *)(a1 + 32);
  v15 = **((_DWORD **)a3 + 16);
  v23 = 0;
  v24 = 0;
  v16 = *((_DWORD *)a3 + 29);
  v17 = *((_DWORD *)a3 + 30);
  LOBYTE(v23) = v13;
  v25 = 0;
  v26 = 0;
  v18 = v16 == 0;
  v19 = *(_QWORD *)(a2 + 64);
  if ( v18 )
    v20 = v17;
  else
    v20 = v15;
  if ( !v18 )
    v15 = v17;
  HIDWORD(v23) = v20;
  LODWORD(v24) = v15;
  LODWORD(v26) = 5;
  hif_hist_record_event(v19, (__int64)&v23, v14);
  if ( !a3 )
    goto LABEL_13;
LABEL_8:
  if ( (*((_DWORD *)a3 + 19) & 0x80000000) != 0 )
  {
    **((_DWORD **)a3 + 18) = *((_DWORD *)a3 + 30);
    v21 = *((_QWORD *)a3 + 11);
    if ( (v21 & 1) == 0 )
      goto LABEL_10;
LABEL_15:
    *((_QWORD *)a3 + 11) = v21 & 0xFFFFFFFFFFFFFFFELL;
    result = raw_spin_unlock_bh(a3 + 80);
    goto LABEL_11;
  }
  hal_delayed_reg_write(v12, a3, *((_QWORD *)a3 + 18), *((unsigned int *)a3 + 30));
  v21 = *((_QWORD *)a3 + 11);
  if ( (v21 & 1) != 0 )
    goto LABEL_15;
LABEL_10:
  result = raw_spin_unlock(a3 + 80);
LABEL_11:
  _ReadStatusReg(SP_EL0);
  return result;
}
