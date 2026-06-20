__int64 __fastcall codec_debug_data_read(__int64 a1, __int64 a2, __int64 a3, _QWORD *a4)
{
  __int64 result; // x0
  __int64 *v6; // x23
  __int64 v7; // x22
  __int64 v8; // x0
  _DWORD *v9; // x8
  int v13; // w0
  _QWORD v14[2]; // [xsp+0h] [xbp-20h] BYREF
  int v15; // [xsp+10h] [xbp-10h]
  __int64 v16; // [xsp+18h] [xbp-8h]

  result = -22;
  v16 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a2 )
  {
    if ( a1 )
    {
      if ( a3 )
      {
        if ( a4 )
        {
          v6 = *(__int64 **)(a1 + 32);
          if ( v6 )
          {
            v15 = 0;
            v14[0] = 0;
            v14[1] = 0;
            v7 = *v6;
            if ( *v6 )
            {
              if ( (*a4 & 0x8000000000000000LL) == 0 )
              {
                v8 = *((unsigned int *)v6 + 4);
                if ( (unsigned int)v8 < 0x40000001 )
                {
                  dev_err(*(_QWORD *)(v7 + 24), "%s: invalid reg_address\n", "codec_debug_data_read");
                }
                else
                {
                  v9 = (_DWORD *)v6[3];
                  if ( *(v9 - 1) != -1896783675 )
                    __break(0x8228u);
                  if ( (((__int64 (__fastcall *)(__int64, __int64, __int64, _QWORD *))v9)(v8, a2, a3, a4) & 1) != 0 )
                  {
                    v13 = snd_soc_component_read(v7, *((unsigned int *)v6 + 4));
                    snprintf((char *)v14, 0x14u, "0x%.8x: 0x%.2x\n", *((_DWORD *)v6 + 4), v13);
                    result = simple_read_from_buffer(a2, a3, a4, v14, 20);
                    goto LABEL_13;
                  }
                  dev_err(
                    *(_QWORD *)(v7 + 24),
                    "%s: 0x%0x isnt't readable\n",
                    "codec_debug_data_read",
                    *((_DWORD *)v6 + 4));
                }
                result = -22;
              }
            }
          }
        }
      }
    }
  }
LABEL_13:
  _ReadStatusReg(SP_EL0);
  return result;
}
