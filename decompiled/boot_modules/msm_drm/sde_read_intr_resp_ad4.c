_QWORD *__fastcall sde_read_intr_resp_ad4(_QWORD *result, int a2, _DWORD *a3, _DWORD *a4)
{
  _QWORD *v4; // x19

  v4 = result;
  if ( !result || !a3 || !a4 )
    return (_QWORD *)_drm_err("invalid params dspp %pK resp_in %pK resp_out %pK\n", result, a3, a4);
  if ( !a2 )
  {
    *a3 = sde_reg_read(result, (unsigned int)(*(_DWORD *)(*(_QWORD *)(result[9] + 48LL) + 344LL) + 44));
    result = (_QWORD *)sde_reg_read(v4, (unsigned int)(*(_DWORD *)(*(_QWORD *)(v4[9] + 48LL) + 344LL) + 72));
    *a4 = (_DWORD)result;
  }
  return result;
}
