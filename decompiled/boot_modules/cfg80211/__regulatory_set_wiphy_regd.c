__int64 __fastcall _regulatory_set_wiphy_regd(__int64 a1, __int64 a2)
{
  __int64 v3; // x8
  __int64 v4; // x9
  __int64 v5; // x8
  unsigned int v6; // w11
  unsigned int v7; // w10
  bool v8; // cf
  unsigned int v9; // w10
  unsigned __int64 v10; // x20
  unsigned __int64 *v11; // x8
  __int64 v12; // x19

  if ( a1 && a2 )
  {
    if ( (*(_BYTE *)(a1 + 104) & 0x80) != 0 )
    {
      v3 = *(unsigned int *)(a2 + 16);
      if ( (_DWORD)v3 )
      {
        if ( (unsigned int)v3 > 0x80 )
        {
          __break(0x800u);
        }
        else
        {
          v4 = 0;
          v5 = 96 * v3;
          while ( 1 )
          {
            v6 = *(_DWORD *)(a2 + v4 + 28);
            if ( !v6 )
              break;
            v7 = *(_DWORD *)(a2 + v4 + 32);
            v8 = v7 >= v6;
            v9 = v7 - v6;
            if ( v9 == 0 || !v8 || *(_DWORD *)(a2 + v4 + 36) > v9 )
              break;
            v4 += 96;
            if ( v5 == v4 )
            {
              v10 = reg_copy_regd(a2);
              if ( v10 < 0xFFFFFFFFFFFFF001LL )
              {
                raw_spin_lock(&reg_requests_lock);
                v11 = (unsigned __int64 *)(a1 - 904);
                v12 = *(_QWORD *)(a1 - 904);
                *v11 = v10;
                raw_spin_unlock(&reg_requests_lock);
                kfree(v12);
                LODWORD(v10) = 0;
              }
              return (unsigned int)v10;
            }
          }
        }
      }
      _warn_printk(
        "Invalid regulatory domain detected: %c%c\n",
        *(unsigned __int8 *)(a2 + 20),
        *(unsigned __int8 *)(a2 + 21));
      __break(0x800u);
      print_rd_rules(a2);
      LODWORD(v10) = -22;
    }
    else
    {
      _warn_printk("wiphy should have REGULATORY_WIPHY_SELF_MANAGED\n");
      __break(0x800u);
      LODWORD(v10) = -1;
    }
  }
  else
  {
    __break(0x800u);
    LODWORD(v10) = -22;
  }
  return (unsigned int)v10;
}
