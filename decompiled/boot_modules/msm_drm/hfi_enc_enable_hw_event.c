__int64 __fastcall hfi_enc_enable_hw_event(__int64 a1, unsigned int a2, char a3)
{
  unsigned int v3; // w8
  __int64 v4; // x20
  unsigned int v5; // w19
  __int64 v6; // x1
  __int64 v7; // x9
  int *v8; // x9
  int v9; // t1
  char v10; // w21
  unsigned int v11; // w0
  unsigned int v13; // w19

  v3 = -22;
  if ( a2 <= 3 )
  {
    v4 = *(_QWORD *)(a1 + 4976);
    if ( v4 )
    {
      if ( (a2 & 1) == 0 )
      {
        if ( a2 )
        {
          if ( a2 != 2 )
          {
            v5 = a2;
            if ( a2 == 1 )
            {
              v10 = a3;
              printk(&unk_24F93B, "_hfi_enc_register_hw_event");
              goto LABEL_11;
            }
            printk(&unk_253277, "_hfi_enc_register_hw_event");
            v13 = -22;
LABEL_17:
            printk(&unk_2734D0, "hfi_enc_enable_hw_event");
            return v13;
          }
          v5 = 2;
          v6 = 1;
        }
        else
        {
          v5 = 0;
          v6 = 2;
        }
        v10 = a3;
        v11 = hfi_enc_hw_event_set_buff(a1, v6, a3 & 1);
        if ( !v11 )
        {
LABEL_11:
          v3 = 0;
          *(_QWORD *)(v4 + 8LL * v5 + 52) = v10 & 1;
          return v3;
        }
        v13 = v11;
        goto LABEL_17;
      }
      v7 = v4 + 8LL * a2;
      v9 = *(_DWORD *)(v7 + 52);
      v8 = (int *)(v7 + 52);
      v3 = 0;
      if ( v9 != (a3 & 1) )
      {
        *v8 = a3 & 1;
        v8[1] = 1;
      }
    }
  }
  return v3;
}
