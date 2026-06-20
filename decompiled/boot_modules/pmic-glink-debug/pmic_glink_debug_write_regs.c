__int64 __fastcall pmic_glink_debug_write_regs(
        __int64 *a1,
        int a2,
        int a3,
        __int16 a4,
        unsigned __int8 *a5,
        __int64 a6)
{
  unsigned int v9; // w23
  int v12; // w9
  __int64 v13; // x0
  int v14; // w0
  __int64 v16; // [xsp+Ch] [xbp-24h] BYREF
  int v17; // [xsp+14h] [xbp-1Ch]
  int v18; // [xsp+18h] [xbp-18h]
  int v19; // [xsp+1Ch] [xbp-14h]
  int v20; // [xsp+20h] [xbp-10h]
  int v21; // [xsp+24h] [xbp-Ch]
  __int64 v22; // [xsp+28h] [xbp-8h]

  LOWORD(v9) = a4;
  v22 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  mutex_lock(a1 + 2);
  while ( 1 )
  {
    v12 = *a5;
    v13 = *a1;
    v16 = 0x10000800FLL;
    v17 = 56;
    v18 = a2;
    v19 = (unsigned __int8)a3;
    v20 = (unsigned __int16)v9;
    v21 = v12;
    *((_DWORD *)a1 + 16) = 0;
    v14 = pmic_glink_write(v13, &v16, 28);
    if ( v14 )
      break;
    if ( !(unsigned int)wait_for_completion_timeout(a1 + 8, 250) )
    {
      dev_err(a1[1], "Error, timed out sending message\n");
      v14 = -110;
      break;
    }
    if ( a6 )
      v9 = (unsigned __int16)v9 + 1;
    else
      v9 = (unsigned __int16)v9;
    if ( a6 )
      ++a5;
    a3 += HIWORD(v9);
    a6 -= a6 != 0;
    if ( !a6 )
      goto LABEL_13;
  }
  LODWORD(a6) = v14;
LABEL_13:
  mutex_unlock(a1 + 2);
  _ReadStatusReg(SP_EL0);
  return (unsigned int)a6;
}
