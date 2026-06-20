__int64 __fastcall hfi_create_full_packet(__int64 a1, __int64 a2)
{
  _DWORD *v2; // x19
  unsigned int v3; // w2
  int v4; // w20
  char *v5; // x8
  size_t v6; // x2
  __int64 result; // x0
  int v8; // w9

  if ( a1 && a2 && (v2 = *(_DWORD **)a1) != nullptr && *(_QWORD *)(a2 + 24) )
  {
    v3 = *(_DWORD *)(a1 + 8);
    if ( v3 <= 0x1F )
    {
      printk(&unk_261BBB, "hfi_validate_cmd_buff_size");
      return 0xFFFFFFFFLL;
    }
    else
    {
      v4 = *(_DWORD *)(a2 + 20) + 32;
      if ( (*v2 & 0xFFFFFFu) + v4 > v3 )
      {
        printk(&unk_27684F, "hfi_validate_cmd_buff_size");
        return 0xFFFFFFFFLL;
      }
      else
      {
        v5 = (char *)v2 + (*v2 & 0xFFFFFF);
        *((_QWORD *)v5 + 2) = 0;
        *((_QWORD *)v5 + 3) = 0;
        *(_QWORD *)v5 = 0;
        *((_QWORD *)v5 + 1) = 0;
        *(_DWORD *)v5 = v4 | (*(_DWORD *)(a2 + 16) << 21);
        *((_DWORD *)v5 + 1) = *(_DWORD *)a2;
        *((_DWORD *)v5 + 2) = *(_DWORD *)(a2 + 8);
        *((_DWORD *)v5 + 3) = *(_DWORD *)(a2 + 4);
        *((_DWORD *)v5 + 4) = *(_DWORD *)(a2 + 12);
        v6 = *(unsigned int *)(a2 + 20);
        if ( (_DWORD)v6 )
          memcpy(v5 + 32, *(const void **)(a2 + 24), v6);
        result = 0;
        v8 = v2[7] + 1;
        *v2 += v4;
        v2[7] = v8;
      }
    }
  }
  else
  {
    printk(&unk_265327, "hfi_create_full_packet");
    return 0xFFFFFFFFLL;
  }
  return result;
}
