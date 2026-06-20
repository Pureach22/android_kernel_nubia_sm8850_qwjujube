__int64 __fastcall ieee80211_key_free_common(__int64 a1)
{
  int v1; // w8

  v1 = *(_DWORD *)(a1 + 544);
  if ( v1 <= 1027081 )
  {
    if ( (unsigned int)(v1 - 1027080) >= 2 && v1 != 1027076 )
    {
      if ( v1 != 1027078 )
        return kfree_sensitive(a1);
      goto LABEL_11;
    }
LABEL_9:
    aead_key_free(*(_QWORD *)(a1 + 152));
    return kfree_sensitive(a1);
  }
  if ( (unsigned int)(v1 - 1027083) < 2 )
  {
    ieee80211_aes_gmac_key_free(*(_QWORD *)(a1 + 56));
    return kfree_sensitive(a1);
  }
  if ( v1 == 1027085 )
  {
LABEL_11:
    ieee80211_aes_cmac_key_free(*(_QWORD *)(a1 + 56));
    return kfree_sensitive(a1);
  }
  if ( v1 == 1027082 )
    goto LABEL_9;
  return kfree_sensitive(a1);
}
