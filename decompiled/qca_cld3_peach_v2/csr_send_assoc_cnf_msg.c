__int64 __fastcall csr_send_assoc_cnf_msg(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        __int64 a9,
        __int64 a10,
        unsigned int a11,
        unsigned int a12)
{
  _DWORD *v15; // x0
  _DWORD *v16; // x20
  int v17; // w8
  size_t v18; // x0
  void *v19; // x0
  size_t v20; // x0
  void *v21; // x0
  char v22; // w8
  __int16 v23; // w9
  __int64 result; // x0
  __int64 v25; // [xsp+8h] [xbp-38h] BYREF
  _DWORD *v26; // [xsp+10h] [xbp-30h]
  __int64 v27; // [xsp+18h] [xbp-28h]
  __int64 v28; // [xsp+20h] [xbp-20h]
  __int64 v29; // [xsp+28h] [xbp-18h]
  __int64 v30; // [xsp+30h] [xbp-10h]
  __int64 v31; // [xsp+38h] [xbp-8h]

  v31 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v29 = 0;
  v30 = 0;
  v27 = 0;
  v28 = 0;
  v25 = 0;
  v26 = nullptr;
  qdf_trace_msg(
    0x34u,
    8u,
    "%s: HalStatus: %d, mac_status_code %d",
    a1,
    a2,
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    "csr_send_assoc_cnf_msg",
    a11,
    a12);
  v15 = (_DWORD *)_qdf_mem_malloc(0x40u, "csr_send_assoc_cnf_msg", 6294);
  if ( !v15 )
    goto LABEL_12;
  v16 = v15;
  *v15 = 4199446;
  if ( a11 )
  {
    v17 = 516;
    v15[6] = a12;
  }
  else
  {
    v17 = 0;
  }
  v15[1] = v17;
  qdf_mem_copy(v15 + 2, (const void *)(a10 + 14), 6u);
  qdf_mem_copy((char *)v16 + 14, (const void *)(a10 + 5), 6u);
  *((_WORD *)v16 + 10) = *(_WORD *)(a10 + 12);
  v18 = *(unsigned int *)(a10 + 2920);
  if ( (_DWORD)v18 )
  {
    v19 = (void *)_qdf_mem_malloc(v18, "csr_send_assoc_cnf_msg", 6315);
    *((_QWORD *)v16 + 4) = v19;
    if ( !v19 )
      goto LABEL_12;
    qdf_mem_copy(v19, *(const void **)(a10 + 2912), *(unsigned int *)(a10 + 2920));
    v16[10] = *(_DWORD *)(a10 + 2920);
  }
  v20 = *(unsigned int *)(a10 + 2936);
  if ( (_DWORD)v20 )
  {
    v21 = (void *)_qdf_mem_malloc(v20, "csr_send_assoc_cnf_msg", 6324);
    *((_QWORD *)v16 + 6) = v21;
    if ( v21 )
    {
      qdf_mem_copy(v21, *(const void **)(a10 + 2928), *(unsigned int *)(a10 + 2936));
      v16[14] = *(_DWORD *)(a10 + 2936);
      goto LABEL_11;
    }
LABEL_12:
    result = 2;
    goto LABEL_13;
  }
LABEL_11:
  v22 = *(_BYTE *)(a10 + 2942);
  v23 = *(_WORD *)v16;
  HIDWORD(v25) = 0;
  *((_BYTE *)v16 + 60) = v22;
  LOWORD(v25) = v23;
  v26 = v16;
  result = scheduler_post_msg_by_priority(53, (unsigned __int16 *)&v25, 1);
LABEL_13:
  _ReadStatusReg(SP_EL0);
  return result;
}
