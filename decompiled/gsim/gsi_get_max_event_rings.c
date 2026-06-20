__int64 __fastcall gsi_get_max_event_rings(int a1)
{
  __int64 result; // x0
  __int64 v2; // x0
  __int64 v3; // [xsp+8h] [xbp-58h] BYREF
  _QWORD v4[4]; // [xsp+10h] [xbp-50h] BYREF
  __int64 v5; // [xsp+30h] [xbp-30h]
  int v6; // [xsp+38h] [xbp-28h]
  _QWORD v7[2]; // [xsp+40h] [xbp-20h] BYREF
  __int64 v8; // [xsp+50h] [xbp-10h]
  __int64 v9; // [xsp+58h] [xbp-8h]

  v9 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v7[1] = 0;
  v8 = 0;
  v7[0] = 0;
  v6 = 0;
  v5 = 0;
  v3 = 0;
  memset(v4, 0, sizeof(v4));
  if ( a1 <= 9 )
  {
    switch ( a1 )
    {
      case 1:
        v2 = 27;
        break;
      case 2:
        v2 = 28;
        break;
      case 0:
LABEL_13:
        dev_err(
          *(_QWORD *)(gsi_ctx + 8),
          "%s:%d GSI version is not supported %d\n",
          "gsi_get_max_event_rings",
          1239,
          a1);
        result = 0;
        __break(0x800u);
        goto LABEL_11;
      default:
LABEL_10:
        ((void (__fastcall *)(__int64, _QWORD, _QWORD *))gsihal_read_reg_n_fields)(
          29,
          *(unsigned int *)(gsi_ctx + 20),
          v4);
        result = (unsigned int)v5;
        goto LABEL_11;
    }
    ((void (__fastcall *)(__int64, _QWORD, _QWORD *))gsihal_read_reg_n_fields)(v2, *(unsigned int *)(gsi_ctx + 20), v7);
    result = HIDWORD(v8);
    goto LABEL_11;
  }
  if ( (unsigned int)(a1 - 10) >= 3 )
  {
    if ( a1 == 14 )
      goto LABEL_13;
    goto LABEL_10;
  }
  ((void (__fastcall *)(__int64, _QWORD, __int64 *))gsihal_read_reg_n_fields)(30, *(unsigned int *)(gsi_ctx + 20), &v3);
  result = HIDWORD(v3);
LABEL_11:
  _ReadStatusReg(SP_EL0);
  return result;
}
