__int64 __fastcall msm_vidc_destroy_output_tx_fence_info(__int64 result, __int64 a2)
{
  int v2; // w8
  unsigned int v3; // w26
  __int64 v4; // x20
  _QWORD *v5; // x19
  __int64 v6; // x21
  __int64 v7; // x8
  __int64 v8; // x24
  __int64 v9; // x28
  __int64 v10; // x4
  __int64 v11; // x25
  _QWORD *v12; // x27
  __int64 v13; // x8
  _DWORD *v14; // x8

  if ( *(_DWORD *)(a2 + 24) == 2
    && (*(_BYTE *)(result + 5544) & 0x80) != 0
    && (~*(_DWORD *)(result + 5528) & 9LL) == 0
    && *(_DWORD *)(result + 14936) == 1 )
  {
    v2 = *(_DWORD *)(a2 + 128);
    v3 = v2 - 1;
    if ( v2 - 1 >= 0 )
    {
      v4 = *(_QWORD *)(result + 320);
      v5 = (_QWORD *)(result + 38352);
      v6 = a2 + 216;
      v7 = (unsigned int)(v2 - 1);
      v8 = a2;
      v9 = result;
      while ( v3 < 0xA )
      {
        v10 = *(_QWORD *)(v6 + 8 * v7);
        v11 = v7;
        v12 = v5;
        do
        {
          v12 = (_QWORD *)*v12;
          if ( v12 == v5 )
          {
            if ( !result )
              goto LABEL_9;
            if ( (msm_vidc_debug & 4) != 0 )
            {
              printk(&unk_97882, "low ", result + 340, "msm_vidc_get_fence_from_id", v10);
              result = v9;
              a2 = v8;
            }
            goto LABEL_23;
          }
        }
        while ( v12[20] != v10 );
        if ( v12 )
        {
          if ( a2 )
          {
            if ( result && (msm_vidc_debug & 1) != 0 )
            {
              printk(&unk_81103, "err ", result + 340, "destroy", v12 + 2);
              goto LABEL_34;
            }
LABEL_27:
            if ( v4 )
              goto LABEL_28;
          }
          else
          {
            if ( !result || (msm_vidc_debug & 1) == 0 )
              goto LABEL_27;
            printk(&unk_915A6, "err ", result + 340, "destroy", v12 + 2);
LABEL_34:
            result = v9;
            a2 = v8;
            if ( v4 )
            {
LABEL_28:
              v13 = *(_QWORD *)(v4 + 6584);
              if ( v13 )
              {
                v14 = *(_DWORD **)(v13 + 48);
                if ( v14 )
                {
                  if ( *(v14 - 1) != -1185588215 )
                    __break(0x8228u);
                  ((void (__fastcall *)(__int64, _QWORD *, __int64))v14)(v9, v12, 1);
                  result = v9;
                  a2 = v8;
                }
              }
            }
          }
          *(_QWORD *)(v6 + 8 * v11) = 0;
          goto LABEL_9;
        }
        if ( result )
        {
LABEL_23:
          if ( (msm_vidc_debug & 1) != 0 )
          {
            printk(&unk_8E723, "err ", result + 340, "msm_vidc_destroy_output_tx_fence_info", *(_QWORD *)(v6 + 8 * v11));
            result = v9;
            a2 = v8;
          }
        }
LABEL_9:
        v7 = v11 - 1;
        if ( !v11 )
          return result;
      }
      __break(0x5512u);
      return populate_fence_name();
    }
  }
  return result;
}
