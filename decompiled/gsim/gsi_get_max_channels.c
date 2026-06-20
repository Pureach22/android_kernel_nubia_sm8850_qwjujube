__int64 __fastcall gsi_get_max_channels(int a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v4; // x4
  __int64 v5; // x0
  __int64 result; // x0
  _QWORD v7[4]; // [xsp+0h] [xbp-50h] BYREF
  __int64 v8; // [xsp+20h] [xbp-30h]
  int v9; // [xsp+28h] [xbp-28h]
  _QWORD v10[2]; // [xsp+30h] [xbp-20h] BYREF
  __int64 v11; // [xsp+40h] [xbp-10h]
  __int64 v12; // [xsp+48h] [xbp-8h]

  v4 = (unsigned int)a1;
  v12 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v10[1] = 0;
  v11 = 0;
  v10[0] = 0;
  v9 = 0;
  v8 = 0;
  memset(v7, 0, sizeof(v7));
  if ( a1 > 1 )
  {
    if ( a1 == 2 )
    {
      v5 = 28;
      goto LABEL_6;
    }
    if ( a1 != 14 )
    {
LABEL_8:
      ((void (__fastcall *)(__int64, _QWORD, _QWORD *))gsihal_read_reg_n_fields)(
        29,
        *(unsigned int *)(gsi_ctx + 20),
        v7);
      result = HIDWORD(v8);
      goto LABEL_9;
    }
LABEL_11:
    dev_err(*(_QWORD *)(gsi_ctx + 8), "%s:%d GSI version is not supported %d\n", "gsi_get_max_channels", 1204, a1);
    result = 0;
    __break(0x800u);
    goto LABEL_9;
  }
  if ( a1 != 1 )
  {
    if ( a1 )
      goto LABEL_8;
    goto LABEL_11;
  }
  v5 = 27;
LABEL_6:
  ((void (__fastcall *)(__int64, _QWORD, _QWORD *, __int64, __int64))gsihal_read_reg_n_fields)(
    v5,
    *(unsigned int *)(gsi_ctx + 20),
    v10,
    a4,
    v4);
  result = (unsigned int)v11;
LABEL_9:
  _ReadStatusReg(SP_EL0);
  return result;
}
