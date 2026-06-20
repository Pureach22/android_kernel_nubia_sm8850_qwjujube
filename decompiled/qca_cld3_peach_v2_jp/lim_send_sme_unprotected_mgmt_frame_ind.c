_BYTE *__fastcall lim_send_sme_unprotected_mgmt_frame_ind(
        __int64 a1,
        char a2,
        const void *a3,
        unsigned int a4,
        char a5)
{
  _BYTE *result; // x0
  _BYTE *v11; // x22
  __int64 v12; // [xsp+8h] [xbp-38h] BYREF
  _BYTE *v13; // [xsp+10h] [xbp-30h]
  __int64 v14; // [xsp+18h] [xbp-28h]
  __int64 v15; // [xsp+20h] [xbp-20h]
  __int64 v16; // [xsp+28h] [xbp-18h]
  __int64 v17; // [xsp+30h] [xbp-10h]
  __int64 v18; // [xsp+38h] [xbp-8h]

  v18 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v16 = 0;
  v17 = 0;
  v14 = 0;
  v15 = 0;
  v12 = 0;
  v13 = nullptr;
  result = (_BYTE *)_qdf_mem_malloc((unsigned __int16)(a4 + 4), "lim_send_sme_unprotected_mgmt_frame_ind", 4863);
  if ( result )
  {
    *result = a5;
    v11 = result;
    result[1] = a2;
    qdf_mem_copy(result + 3, a3, a4);
    v11[2] = a4;
    LOWORD(v12) = 5194;
    v13 = v11;
    HIDWORD(v12) = 0;
    result = (_BYTE *)sys_process_mmh_msg(a1, &v12);
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
