__int64 __fastcall syna_dev_set_follow_hand_level(_QWORD *a1, int a2, unsigned int a3)
{
  void *v6; // x0
  __int64 result; // x0

  printk(unk_3A85B, "syna_dev_set_follow_hand_level", "syna_dev_set_follow_hand_level");
  if ( !a1 )
    return 4294967274LL;
  v6 = unk_3BDBF;
  if ( a2 <= 1 )
  {
    if ( a2 )
    {
      if ( a2 == 1 )
      {
        result = syna_tcm_set_dynamic_config(*a1, 249, *((_DWORD *)a1 + 383) | (*((_DWORD *)a1 + 385) << 8) | 0x10u, a3);
        if ( (result & 0x80000000) != 0 )
          return result;
        v6 = unk_387C8;
      }
    }
    else
    {
      result = syna_tcm_set_dynamic_config(
                 *a1,
                 249,
                 (unsigned int)(*((_DWORD *)a1 + 383) | (*((_DWORD *)a1 + 385) << 8)),
                 a3);
      if ( (result & 0x80000000) != 0 )
        return result;
      v6 = unk_3B08C;
    }
  }
  else
  {
    switch ( a2 )
    {
      case 2:
        result = syna_tcm_set_dynamic_config(*a1, 249, *((_DWORD *)a1 + 383) | (*((_DWORD *)a1 + 385) << 8) | 0x20u, a3);
        if ( (result & 0x80000000) != 0 )
          return result;
        v6 = unk_3A1C3;
        break;
      case 3:
        result = syna_tcm_set_dynamic_config(*a1, 249, *((_DWORD *)a1 + 383) | (*((_DWORD *)a1 + 385) << 8) | 0x30u, a3);
        if ( (result & 0x80000000) != 0 )
          return result;
        v6 = unk_3981B;
        break;
      case 4:
        result = syna_tcm_set_dynamic_config(*a1, 249, *((_DWORD *)a1 + 383) | (*((_DWORD *)a1 + 385) << 8) | 0x40u, a3);
        if ( (result & 0x80000000) != 0 )
          return result;
        v6 = unk_3B75C;
        break;
    }
  }
  printk(v6, "syna_dev_set_follow_hand_level", "syna_dev_set_follow_hand_level");
  return 0;
}
