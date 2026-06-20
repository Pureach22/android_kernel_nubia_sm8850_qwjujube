__int64 __fastcall battery_dbg_callback(__int64 a1, unsigned int *src, unsigned __int64 a3)
{
  __int64 v4; // x2
  size_t v6; // x20
  __int64 v7; // x2
  int v8; // w8
  __int64 v9; // x23
  const char *v10; // x20
  unsigned int v11; // w9
  void *v13; // x0
  const char *v14; // x1

  v4 = src[2];
  if ( (int)v4 > 22 )
  {
    if ( (_DWORD)v4 == 23 )
    {
      if ( a3 == 192 )
      {
        v7 = src[3];
        if ( (unsigned int)v7 >= 0xC )
        {
          v13 = &unk_7605;
          v14 = "handle_get_votable_message";
        }
        else
        {
          if ( !src[45] || (v11 = src[46], v11 < 0x20) )
          {
            memcpy((void *)(*(_QWORD *)(a1 + 4768) + 208LL * (unsigned int)v7 + 24), src + 3, 0xB4u);
            goto LABEL_23;
          }
          v13 = &unk_77ED;
          v14 = "handle_get_votable_message";
          v7 = v11;
        }
      }
      else
      {
        v13 = &unk_75A7;
        v14 = "handle_get_votable_message";
        v7 = 192;
      }
    }
    else
    {
      if ( (_DWORD)v4 != 54 )
      {
LABEL_26:
        printk(&unk_76D8, "battery_dbg_callback", v4);
        return 0;
      }
      if ( a3 < 0x1011 )
      {
        v6 = src[3];
        if ( (unsigned int)v6 > 0x1000 )
        {
          printk(&unk_7919, "handle_qbg_dump_message", (unsigned int)v6);
          return 0;
        }
        memcpy((void *)(a1 + 112), src + 4, v6);
        *(_QWORD *)(a1 + 4224) = v6;
        goto LABEL_23;
      }
      v13 = &unk_7796;
      v14 = "handle_qbg_dump_message";
      v7 = a3;
    }
LABEL_35:
    printk(v13, v14, v7);
    return 0;
  }
  if ( (_DWORD)v4 == 21 )
  {
    if ( a3 == 548 )
    {
      v7 = src[3];
      if ( (unsigned int)v7 >= 0xC )
      {
        v13 = &unk_78AF;
        v14 = "handle_get_votables_list_message";
      }
      else
      {
        v7 = src[4];
        if ( (unsigned int)v7 < 0x20 )
        {
          memcpy((void *)(a1 + 4232), src + 3, 0x218u);
          v8 = *(unsigned __int8 *)(a1 + 4776);
          *(_BYTE *)(a1 + 4251) = 0;
          *(_BYTE *)(a1 + 4263) = 0;
          *(_BYTE *)(a1 + 4275) = 0;
          *(_BYTE *)(a1 + 4287) = 0;
          *(_BYTE *)(a1 + 4299) = 0;
          *(_BYTE *)(a1 + 4311) = 0;
          *(_BYTE *)(a1 + 4323) = 0;
          *(_BYTE *)(a1 + 4335) = 0;
          *(_BYTE *)(a1 + 4347) = 0;
          *(_BYTE *)(a1 + 4359) = 0;
          *(_BYTE *)(a1 + 4371) = 0;
          *(_BYTE *)(a1 + 4383) = 0;
          *(_BYTE *)(a1 + 4395) = 0;
          *(_BYTE *)(a1 + 4407) = 0;
          *(_BYTE *)(a1 + 4419) = 0;
          *(_BYTE *)(a1 + 4431) = 0;
          *(_BYTE *)(a1 + 4443) = 0;
          *(_BYTE *)(a1 + 4455) = 0;
          *(_BYTE *)(a1 + 4467) = 0;
          *(_BYTE *)(a1 + 4479) = 0;
          *(_BYTE *)(a1 + 4491) = 0;
          *(_BYTE *)(a1 + 4503) = 0;
          *(_BYTE *)(a1 + 4515) = 0;
          *(_BYTE *)(a1 + 4527) = 0;
          *(_BYTE *)(a1 + 4539) = 0;
          *(_BYTE *)(a1 + 4551) = 0;
          *(_BYTE *)(a1 + 4563) = 0;
          *(_BYTE *)(a1 + 4575) = 0;
          *(_BYTE *)(a1 + 4587) = 0;
          *(_BYTE *)(a1 + 4599) = 0;
          *(_BYTE *)(a1 + 4611) = 0;
          *(_BYTE *)(a1 + 4623) = 0;
          *(_BYTE *)(a1 + 4635) = 0;
          *(_BYTE *)(a1 + 4647) = 0;
          *(_BYTE *)(a1 + 4659) = 0;
          *(_BYTE *)(a1 + 4671) = 0;
          *(_BYTE *)(a1 + 4683) = 0;
          *(_BYTE *)(a1 + 4695) = 0;
          *(_BYTE *)(a1 + 4707) = 0;
          *(_BYTE *)(a1 + 4719) = 0;
          *(_BYTE *)(a1 + 4731) = 0;
          *(_BYTE *)(a1 + 4743) = 0;
          *(_BYTE *)(a1 + 4755) = 0;
          *(_BYTE *)(a1 + 4767) = 0;
          if ( !v8 )
          {
            v9 = 0;
            v10 = (const char *)(a1 + 4384);
            while ( strcmp(v10, "glink") )
            {
              ++v9;
              v10 += 12;
              if ( v9 == 32 )
                goto LABEL_23;
            }
            *(_BYTE *)(a1 + 4776) = v9;
          }
          goto LABEL_23;
        }
        v13 = &unk_79C0;
        v14 = "handle_get_votables_list_message";
      }
    }
    else
    {
      v13 = &unk_75A7;
      v14 = "handle_get_votables_list_message";
      v7 = 548;
    }
    goto LABEL_35;
  }
  if ( (_DWORD)v4 != 22 )
    goto LABEL_26;
LABEL_23:
  complete(a1 + 64);
  return 0;
}
