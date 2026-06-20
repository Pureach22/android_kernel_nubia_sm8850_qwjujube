_QWORD *__fastcall dspp_ai_scaler(_QWORD *result)
{
  __int64 v1; // x8
  __int64 v2; // x8
  __int64 v3; // x8

  if ( !result )
    return (_QWORD *)printk(&unk_26FEB0, "dspp_ai_scaler");
  v1 = result[188];
  if ( v1 )
  {
    v2 = *(_QWORD *)(v1 + 152);
    if ( v2 )
    {
      if ( (*(_BYTE *)(v2 + 20112) & 1) != 0 )
      {
        v3 = *(_QWORD *)(result[9] + 48LL);
        if ( *(_DWORD *)(v3 + 724) == 0x10000 && *(_BYTE *)(v3 + 732) == 1 )
        {
          result[176] = sde_check_ai_scaler_v1;
          result[179] = &sde_setup_ai_scaler_v1;
        }
      }
      else if ( (_drm_debug & 4) != 0 )
      {
        return (_QWORD *)printk(&unk_269B57, *(unsigned __int8 *)(v2 + 20112));
      }
      else
      {
        return (_QWORD *)printk(&unk_25BAC7, "dspp_ai_scaler");
      }
    }
  }
  return result;
}
