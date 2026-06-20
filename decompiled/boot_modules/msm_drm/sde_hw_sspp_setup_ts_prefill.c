__int64 __fastcall sde_hw_sspp_setup_ts_prefill(__int64 result, _QWORD *a2, unsigned int a3)
{
  __int64 v3; // x8
  unsigned int v4; // w8
  unsigned int v5; // w19
  __int64 v6; // x9
  unsigned __int64 v7; // x20
  int v8; // w9
  unsigned int v9; // w2
  __int64 v10; // x21

  if ( result )
  {
    if ( a2 )
    {
      v3 = *(_QWORD *)(result + 56);
      if ( v3 )
      {
        if ( a3 > 1 )
        {
          if ( a3 == 2 && (*(_QWORD *)(v3 + 40) & 0x10) != 0 )
          {
            v4 = 344;
            v5 = 340;
            v6 = a2[1];
            if ( v6 )
              goto LABEL_7;
            goto LABEL_16;
          }
        }
        else if ( (*(_QWORD *)(v3 + 40) & 8) != 0 )
        {
          v4 = 304;
          v5 = 336;
          v6 = a2[1];
          if ( v6 )
          {
LABEL_7:
            v7 = (19200000 * v6 + 999999) / 0xF4240uLL;
            if ( (unsigned int)(((unsigned __int64)(unsigned int)v7 + *a2 - 1) / (unsigned int)v7) >= 0xFF )
              v8 = 255;
            else
              v8 = ((unsigned __int64)(unsigned int)v7 + *a2 - 1) / (unsigned int)v7;
            if ( (_DWORD)v7 )
              v9 = v8 | 0x88000000;
            else
              v9 = v8;
            goto LABEL_17;
          }
LABEL_16:
          LODWORD(v7) = 0;
          v9 = 0;
LABEL_17:
          v10 = result;
          sde_reg_write(result, v4, v9, "ts_offset");
          return sde_reg_write(v10, v5, v7, "ts_prefill_offset");
        }
        return printk(&unk_27E748, "sde_hw_sspp_setup_ts_prefill");
      }
    }
  }
  return result;
}
