__int64 __fastcall hfi_get_extened_format(int a1)
{
  char *v1; // x8
  __int64 v2; // x10
  __int64 v3; // x9
  bool v4; // zf
  unsigned int v5; // w19
  _DWORD *v6; // x8

  v1 = (char *)&sde_linear_fmt_map;
  if ( a1 != 16777217 )
  {
    v2 = 0;
    while ( 1 )
    {
      v3 = v2 + 16;
      if ( v2 == 720 )
        break;
      v4 = *(_DWORD *)((char *)&sde_linear_fmt_map + v2 + 16) == a1;
      v2 += 16;
      if ( v4 )
      {
        v1 = (char *)&sde_linear_fmt_map + v3;
        if ( (unsigned __int64)(v3 + 4) <= 0x2E0 )
          goto LABEL_7;
        __break(1u);
        return hfi_catalog_get_hfi_format();
      }
    }
LABEL_8:
    v5 = 0;
    if ( a1 > 50331651 )
    {
      if ( a1 <= 67108865 )
      {
        if ( a1 > 50331653 )
        {
          if ( a1 == 50331654 )
          {
            v6 = &unk_285FE0;
          }
          else
          {
            if ( a1 != 67108865 )
              goto LABEL_50;
            v6 = &unk_285FF0;
          }
        }
        else if ( a1 == 50331652 )
        {
          v6 = &unk_285FC0;
        }
        else
        {
          v6 = &unk_285FD0;
        }
      }
      else if ( a1 <= 100663296 )
      {
        if ( a1 == 67108866 )
        {
          v6 = &unk_286000;
        }
        else
        {
          if ( a1 != 83886085 )
            goto LABEL_50;
          v6 = &unk_286010;
        }
      }
      else
      {
        switch ( a1 )
        {
          case 100663297:
            v6 = &unk_286020;
            break;
          case 100663299:
            v6 = &unk_286030;
            break;
          case 100663300:
            v6 = &unk_286040;
            break;
          default:
            goto LABEL_50;
        }
      }
    }
    else if ( a1 <= 16777239 )
    {
      if ( a1 > 16777237 )
      {
        if ( a1 == 16777238 )
          v6 = &unk_285F40;
        else
          v6 = &unk_285F50;
      }
      else if ( a1 == 16777235 )
      {
        v6 = &unk_285F80;
      }
      else
      {
        if ( a1 != 16777237 )
          goto LABEL_50;
        v6 = &sde_non_linear_fmt_map;
      }
    }
    else if ( a1 <= 50331648 )
    {
      if ( a1 == 16777240 )
      {
        v6 = &unk_285F60;
      }
      else
      {
        if ( a1 != 33554451 )
          goto LABEL_50;
        v6 = &unk_285F70;
      }
    }
    else if ( a1 == 50331649 )
    {
      v6 = &unk_285F90;
    }
    else if ( a1 == 50331650 )
    {
      v6 = &unk_285FA0;
    }
    else
    {
      v6 = &unk_285FB0;
    }
    v5 = v6[1];
    if ( v5 )
      return v5;
LABEL_50:
    printk(&unk_23141E, "hfi_get_extened_format");
    return v5;
  }
LABEL_7:
  v5 = *((_DWORD *)v1 + 1);
  if ( !v5 )
    goto LABEL_8;
  return v5;
}
