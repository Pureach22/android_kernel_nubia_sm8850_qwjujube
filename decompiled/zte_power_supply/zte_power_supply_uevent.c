__int64 __fastcall zte_power_supply_uevent(__int64 a1, __int64 a2)
{
  const char ***v2; // x23
  __int64 result; // x0
  char *zeroed_page_noprof; // x21
  const char **v7; // x8
  unsigned __int64 v8; // x9
  int v9; // w24
  unsigned int v10; // w27
  const char **v11; // x28
  __int64 v12; // x0
  char *v14; // x0
  __int64 v15; // x19
  unsigned __int64 StatusReg; // x22
  __int64 v17; // x24

  v2 = *(const char ****)(a1 + 152);
  if ( !v2 || !*v2 )
    return 0;
  result = add_uevent_var(a2, "POWER_SUPPLY_NAME=%s", **v2);
  if ( !(_DWORD)result )
  {
    zeroed_page_noprof = (char *)get_zeroed_page_noprof(3264);
    if ( zeroed_page_noprof )
    {
      while ( 1 )
      {
        v7 = *v2;
        if ( !(*v2)[5] )
          break;
        v8 = 0;
        v9 = 1;
        while ( 1 )
        {
          v10 = *(_DWORD *)&v7[4][4 * v8];
          if ( v10 >= 0x14 )
            break;
          v11 = (const char **)&(&zte_power_supply_attrs)[11 * v10];
          v12 = zte_power_supply_show_property(a1, (__int64)(v11 + 5), zeroed_page_noprof);
          if ( (_DWORD)v12 != -61 && (_DWORD)v12 != -19 )
          {
            if ( (v12 & 0x80000000) != 0 )
              goto LABEL_22;
            v14 = strchr(zeroed_page_noprof, 10);
            if ( v14 )
              *v14 = 0;
            if ( v10 == 19 )
              goto LABEL_24;
            v12 = add_uevent_var(a2, "POWER_SUPPLY_%s=%s", *v11, zeroed_page_noprof);
            if ( (_DWORD)v12 )
              goto LABEL_22;
          }
          v7 = *v2;
          v8 = v9++;
          if ( (unsigned __int64)(*v2)[5] <= v8 )
            goto LABEL_21;
        }
        __break(0x5512u);
LABEL_24:
        __break(1u);
        StatusReg = _ReadStatusReg(SP_EL0);
        v17 = *(_QWORD *)(StatusReg + 80);
        *(_QWORD *)(StatusReg + 80) = &zte_power_supply_uevent__alloc_tag;
        zeroed_page_noprof = (char *)get_zeroed_page_noprof(3264);
        *(_QWORD *)(StatusReg + 80) = v17;
        if ( !zeroed_page_noprof )
          return 4294967284LL;
      }
LABEL_21:
      v12 = 0;
LABEL_22:
      v15 = v12;
      free_pages(zeroed_page_noprof, 0);
      return v15;
    }
    else
    {
      return 4294967284LL;
    }
  }
  return result;
}
