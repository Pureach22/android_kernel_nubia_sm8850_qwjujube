__int64 __fastcall hw_fence_init_controller_signal(__int64 a1, __int64 a2)
{
  __int64 v2; // x30
  __int64 v3; // x4
  unsigned int v4; // w8
  __int64 v5; // x20
  __int64 v6; // x19
  int client_id_priv; // w0
  _BYTE *v8; // x2
  unsigned int v9; // w3
  __int64 v10; // x20
  __int64 v11; // x19
  int v12; // w0
  __int64 v13; // x20
  __int64 v14; // x19
  int v15; // w0
  __int64 v16; // x20
  __int64 v17; // x19
  int v18; // w0
  __int64 v19; // x20
  __int64 v20; // x19
  int v21; // w0

  v3 = *(unsigned int *)(a2 + 4);
  v4 = 0;
  if ( (int)v3 <= 512 )
  {
    if ( (int)v3 <= 192 && (unsigned int)(v3 - 1) >= 0x40 )
    {
      if ( (unsigned int)(v3 - 65) < 0x40 )
      {
        v8 = (_BYTE *)(a1 + 737);
        v9 = 65;
        return (unsigned int)init_input_controller_signal(a1, a2, v8, v9);
      }
      if ( (unsigned int)(v3 - 129) < 0x40 )
      {
        if ( *(_DWORD *)(a2 + 168) == *(_DWORD *)(a1 + 628) )
        {
          if ( (*(_BYTE *)(a1 + 739) & 1) == 0 )
          {
            v5 = a2;
            v6 = a1;
            client_id_priv = hw_fence_utils_get_client_id_priv(a1, 129);
            *(_DWORD *)(v6 + 744) = 129;
            v8 = (_BYTE *)(v6 + 739);
            a2 = v5;
            *(_DWORD *)(v6 + 740) = client_id_priv;
            a1 = v6;
            v9 = 129;
            return (unsigned int)init_input_controller_signal(a1, a2, v8, v9);
          }
          return 0;
        }
        goto LABEL_34;
      }
      goto LABEL_18;
    }
    return v4;
  }
  if ( (int)v3 <= 704 )
  {
    if ( (unsigned int)(v3 - 513) < 0x40 )
    {
      v8 = (_BYTE *)(a1 + 738);
      v9 = 513;
      return (unsigned int)init_input_controller_signal(a1, a2, v8, v9);
    }
    if ( (unsigned int)(v3 - 577) < 0x40 )
    {
      if ( *(_DWORD *)(a2 + 168) == *(_DWORD *)(a1 + 628) )
      {
        if ( (*(_BYTE *)(a1 + 739) & 1) == 0 )
        {
          v16 = a2;
          v17 = a1;
          v18 = hw_fence_utils_get_client_id_priv(a1, 577);
          *(_DWORD *)(v17 + 744) = 577;
          v8 = (_BYTE *)(v17 + 739);
          a2 = v16;
          *(_DWORD *)(v17 + 740) = v18;
          a1 = v17;
          v9 = 577;
          return (unsigned int)init_input_controller_signal(a1, a2, v8, v9);
        }
        return 0;
      }
    }
    else if ( *(_DWORD *)(a2 + 168) == *(_DWORD *)(a1 + 628) )
    {
      if ( (*(_BYTE *)(a1 + 739) & 1) == 0 )
      {
        v10 = a2;
        v11 = a1;
        v12 = hw_fence_utils_get_client_id_priv(a1, 641);
        *(_DWORD *)(v11 + 744) = 641;
        v8 = (_BYTE *)(v11 + 739);
        a2 = v10;
        *(_DWORD *)(v11 + 740) = v12;
        a1 = v11;
        v9 = 641;
        return (unsigned int)init_input_controller_signal(a1, a2, v8, v9);
      }
      return 0;
    }
    goto LABEL_34;
  }
  if ( (unsigned int)(v3 - 705) < 0x40 )
  {
    if ( *(_DWORD *)(a2 + 168) == *(_DWORD *)(a1 + 628) )
    {
      if ( (*(_BYTE *)(a1 + 739) & 1) == 0 )
      {
        v13 = a2;
        v14 = a1;
        v15 = hw_fence_utils_get_client_id_priv(a1, 705);
        *(_DWORD *)(v14 + 744) = 705;
        v8 = (_BYTE *)(v14 + 739);
        a2 = v13;
        *(_DWORD *)(v14 + 740) = v15;
        a1 = v14;
        v9 = 705;
        return (unsigned int)init_input_controller_signal(a1, a2, v8, v9);
      }
      return 0;
    }
    goto LABEL_34;
  }
  if ( (unsigned int)(v3 - 769) < 0x40 )
  {
    if ( *(_DWORD *)(a2 + 168) == *(_DWORD *)(a1 + 628) )
    {
      if ( (*(_BYTE *)(a1 + 739) & 1) == 0 )
      {
        v19 = a2;
        v20 = a1;
        v21 = hw_fence_utils_get_client_id_priv(a1, 769);
        *(_DWORD *)(v20 + 744) = 769;
        v8 = (_BYTE *)(v20 + 739);
        a2 = v19;
        *(_DWORD *)(v20 + 740) = v21;
        a1 = v20;
        v9 = 769;
        return (unsigned int)init_input_controller_signal(a1, a2, v8, v9);
      }
      return 0;
    }
LABEL_34:
    printk(&unk_27927, "_init_val_controller_signal", 958, v2, v3);
    return (unsigned int)-22;
  }
  if ( (unsigned int)(v3 - 833) >= 0x40 )
  {
LABEL_18:
    if ( (unsigned int)(v3 - 897) >= 0x300 )
    {
      printk(&unk_26B0A, "hw_fence_init_controller_signal", 1065, v2, v3);
      return (unsigned int)-22;
    }
    return 0;
  }
  return v4;
}
