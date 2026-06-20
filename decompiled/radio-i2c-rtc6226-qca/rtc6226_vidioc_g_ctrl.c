__int64 __fastcall rtc6226_vidioc_g_ctrl(__int64 a1, __int64 a2, int *a3)
{
  __int64 v4; // x19
  int v5; // w8
  unsigned int v6; // w21
  unsigned __int16 v7; // w9
  unsigned __int16 v8; // w9
  int v9; // w8

  v4 = *(_QWORD *)(video_devdata() + 336);
  mutex_lock(v4 + 1872);
  v5 = *a3;
  v6 = 0;
  if ( *a3 > 10025223 )
  {
    if ( v5 <= 10025232 )
    {
      if ( v5 == 10025224 )
        goto LABEL_23;
      if ( v5 != 10025225 )
      {
        if ( v5 == 10025230 )
        {
          v6 = 0;
          a3[1] = *(_WORD *)(v4 + 1772) & 0xF00;
          goto LABEL_29;
        }
        goto LABEL_30;
      }
      v9 = *(_DWORD *)(v4 + 1744);
    }
    else
    {
      if ( v5 > 134217743 )
      {
        if ( v5 == 134217744 )
          goto LABEL_29;
        v8 = 62;
      }
      else
      {
        if ( v5 == 10025233 )
        {
          rtc6226_get_all_registers(v4);
          v9 = *(unsigned __int8 *)(v4 + 1784);
          goto LABEL_28;
        }
        v8 = 8;
      }
      if ( v5 != (v8 | 0x8000000) )
        goto LABEL_30;
      v9 = *(unsigned __int8 *)(v4 + 1761);
    }
LABEL_28:
    v6 = 0;
    a3[1] = v9;
    goto LABEL_29;
  }
  if ( v5 > 10025218 )
  {
    if ( v5 != 10025219 )
    {
      if ( v5 == 10025220 )
      {
        v6 = 0;
        a3[1] = (*(unsigned __int16 *)(v4 + 1766) >> 15) ^ 1;
        goto LABEL_29;
      }
      v7 = -1787;
LABEL_13:
      if ( v5 == (v7 | 0x980000) )
      {
        v6 = 0;
        a3[1] = (*(_WORD *)(v4 + 1766) & 0x4000) == 0;
        goto LABEL_29;
      }
LABEL_30:
      v6 = -22;
      goto LABEL_29;
    }
    v9 = *(unsigned __int16 *)(v4 + 1762);
    goto LABEL_28;
  }
  if ( (unsigned int)(v5 - 10025217) >= 2 )
  {
    if ( v5 != 9963781 )
    {
      v7 = 2313;
      goto LABEL_13;
    }
LABEL_23:
    v6 = 0;
    a3[1] = *(_WORD *)(v4 + 1766) & 0xF;
  }
LABEL_29:
  mutex_unlock(v4 + 1872);
  return v6;
}
