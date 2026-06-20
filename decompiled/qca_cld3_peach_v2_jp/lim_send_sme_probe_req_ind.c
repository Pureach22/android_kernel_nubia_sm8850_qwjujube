__int64 __fastcall lim_send_sme_probe_req_ind(__int64 a1, const void *a2, const void *a3, unsigned int a4, __int64 a5)
{
  __int64 result; // x0
  _WORD *v11; // x24
  size_t v12; // x2
  __int64 v13; // [xsp+8h] [xbp-38h] BYREF
  __int64 v14; // [xsp+10h] [xbp-30h]
  __int64 v15; // [xsp+18h] [xbp-28h]
  __int64 v16; // [xsp+20h] [xbp-20h]
  __int64 v17; // [xsp+28h] [xbp-18h]
  __int64 v18; // [xsp+30h] [xbp-10h]
  __int64 v19; // [xsp+38h] [xbp-8h]

  v19 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v17 = 0;
  v18 = 0;
  v15 = 0;
  v16 = 0;
  v13 = 0;
  v14 = 0;
  result = _qdf_mem_malloc(0x214u, "lim_send_sme_probe_req_ind", 590);
  if ( result )
  {
    HIDWORD(v13) = 0;
    v11 = (_WORD *)result;
    LOWORD(v13) = 5157;
    v14 = result;
    *(_DWORD *)result = 34870309;
    *(_BYTE *)(result + 4) = *(_BYTE *)(a5 + 10);
    qdf_mem_copy((void *)(result + 5), (const void *)(a5 + 24), 6u);
    qdf_mem_copy(v11 + 6, a2, 6u);
    qdf_trace(53, 6u, *(_WORD *)(a5 + 8), 5157);
    if ( a4 >= 0x200 )
      v12 = 512;
    else
      v12 = a4;
    v11[9] = v12;
    qdf_mem_copy(v11 + 10, a3, v12);
    result = sys_process_mmh_msg(a1, &v13);
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
