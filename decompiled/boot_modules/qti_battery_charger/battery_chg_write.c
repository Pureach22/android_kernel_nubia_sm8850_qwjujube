__int64 __fastcall battery_chg_write(__int64 a1, __int64 a2, unsigned int a3, unsigned int a4)
{
  int v8; // w23
  __int64 v10; // x0
  int v11; // w0
  __int64 v12; // x0
  __int64 v13; // x2
  unsigned int v14; // w20

  down_read(a1 + 192);
  v8 = *(_DWORD *)(a1 + 556);
  up_read(a1 + 192);
  if ( !v8 || *(_BYTE *)(a1 + 1077) == 1 && (*(_BYTE *)(a1 + 1044) & 1) != 0 )
    return 0;
  mutex_lock(a1 + 144);
  v10 = *(_QWORD *)(a1 + 136);
  *(_DWORD *)(a1 + 256) = 0;
  *(_BYTE *)(a1 + 1165) = 0;
  v11 = pmic_glink_write(v10, a2, a3);
  if ( !v11 )
  {
    v12 = _msecs_to_jiffies(a4);
    if ( (unsigned int)wait_for_completion_timeout(a1 + 256, v12) )
    {
      if ( *(_BYTE *)(a1 + 1165) == 1 )
      {
        v11 = -61;
        *(_BYTE *)(a1 + 1165) = 0;
      }
      else
      {
        v11 = 0;
      }
    }
    else
    {
      printk(&unk_FDF2, "battery_chg_write", v13);
      v11 = -110;
    }
  }
  v14 = v11;
  mutex_unlock(a1 + 144);
  return v14;
}
