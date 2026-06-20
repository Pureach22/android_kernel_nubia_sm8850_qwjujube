__int64 __fastcall pmic_glink_debug_read_regs(__int64 *a1, int a2, int a3, __int16 a4, char *a5, unsigned __int64 a6)
{
  unsigned int v9; // w23
  __int64 v12; // x0
  __int64 v13; // x8
  size_t v14; // x25
  int v15; // w0
  __int64 v17; // [xsp+Ch] [xbp-24h] BYREF
  int v18; // [xsp+14h] [xbp-1Ch]
  int v19; // [xsp+18h] [xbp-18h]
  int v20; // [xsp+1Ch] [xbp-14h]
  int v21; // [xsp+20h] [xbp-10h]
  int v22; // [xsp+24h] [xbp-Ch]
  __int64 v23; // [xsp+28h] [xbp-8h]

  LOWORD(v9) = a4;
  v23 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  mutex_lock(a1 + 2);
  while ( 1 )
  {
    v12 = *a1;
    if ( a6 >= 0x100 )
      v13 = 256;
    else
      v13 = a6;
    v17 = 0x10000800FLL;
    v18 = 55;
    v19 = a2;
    *((_DWORD *)a1 + 16) = 0;
    if ( v13 + (unsigned __int64)(unsigned __int8)v9 <= 0x100 )
      v14 = (unsigned int)v13;
    else
      v14 = 256 - (unsigned int)(unsigned __int8)v9;
    v20 = (unsigned __int8)a3;
    v21 = (unsigned __int16)v9;
    v22 = v14;
    v15 = pmic_glink_write(v12, &v17, 28);
    if ( v15 )
      goto LABEL_14;
    if ( !(unsigned int)wait_for_completion_timeout(a1 + 8, 250) )
      break;
    if ( *((_DWORD *)a1 + 30) != (_DWORD)v14 )
    {
      v15 = -22;
LABEL_14:
      LODWORD(a6) = v15;
      goto LABEL_15;
    }
    memcpy(a5, (char *)a1 + 124, v14);
    a6 -= v14;
    a5 += v14;
    v9 = (unsigned __int16)v9 + (unsigned __int16)v14;
    a3 += HIWORD(v9);
    if ( !a6 )
      goto LABEL_15;
  }
  dev_err(a1[1], "Error, timed out sending message\n");
  LODWORD(a6) = -110;
LABEL_15:
  mutex_unlock(a1 + 2);
  _ReadStatusReg(SP_EL0);
  return (unsigned int)a6;
}
