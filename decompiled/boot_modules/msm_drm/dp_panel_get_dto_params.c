__int64 __fastcall dp_panel_get_dto_params(__int64 result, _DWORD *a2)
{
  int v2; // w8
  _DWORD *v3; // x9
  unsigned int v4; // w8
  unsigned int v5; // w9
  __int64 ipc_log_context; // x0

  v2 = a2[1];
  if ( v2 != 30 )
  {
    if ( v2 == 24 )
    {
      if ( *a2 == 12 )
      {
        v3 = &dp_dsc_num_denom;
        goto LABEL_15;
      }
      if ( *a2 == 8 )
      {
        v3 = &unk_280D70;
        goto LABEL_15;
      }
    }
LABEL_12:
    v4 = 0;
    v5 = 1;
    if ( (_DWORD)result == 4 )
      goto LABEL_16;
LABEL_13:
    a2[2] = v4;
    a2[3] = v5;
    return result;
  }
  switch ( *a2 )
  {
    case 0xF:
      v3 = &unk_280D60;
      break;
    case 8:
      v3 = &unk_280D80;
      break;
    case 0xA:
      v3 = &unk_280D90;
      break;
    default:
      goto LABEL_12;
  }
LABEL_15:
  v4 = v3[2];
  v5 = v3[3];
  if ( (_DWORD)result != 4 )
    goto LABEL_13;
LABEL_16:
  v4 *= 2;
  if ( v4 <= v5 )
    goto LABEL_13;
  ipc_log_context = get_ipc_log_context(result);
  ipc_log_string(ipc_log_context, "[e][%-4d]dto params not supported\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
  result = printk(&unk_214C77, "dp_panel_get_dto_params");
  a2[2] = 0;
  a2[3] = 1;
  return result;
}
