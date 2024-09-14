void sol()
{
    int n; cin >> n;
    string ans, vowels = "aeiou";
    for (int i=0; i<n; i++)
    {
        ans += vowels[i%5];
    }
    sort(all(ans));
    cout << ans << el;
}